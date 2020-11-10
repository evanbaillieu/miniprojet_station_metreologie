#include "lecteurrfidioserviceimpl.h"

PhysiqueIO::LecteurRFIDIOServiceImpl::LecteurRFIDIOServiceImpl()
{
    typeSrv = MetierFactory::getTypeServiceImpl();
    fctEcrire = "5200";
    fctLire = "4200";
    port = 2101;
    ip = "172.16.79.102";

    connect(&tcpSocket, SIGNAL(connected()), this, SLOT(connexionOK()));
    connect(&tcpSocket, SIGNAL(disconnected()), this, SLOT(deconnexionOK()));
    connect(&tcpSocket, SIGNAL(readyRead()),this, SLOT(readDatagram()));
    connect(&tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(detectErreur()));
}


PhysiqueIO::LecteurRFIDIOServiceImpl::~LecteurRFIDIOServiceImpl(){
    deconnexion();
}

Materiel PhysiqueIO::LecteurRFIDIOServiceImpl::lireBadge()
{
    contenuBadge.clear();
    QEventLoop loop;
    connect(this, SIGNAL(dataOk(bool)), &loop,SLOT(quit()));
    Materiel materiel = Materiel();
    connexion(ip, port);
    if(connexionEtat == true){
        construireLigne(fctLire, "s000f");
        envoiTrame(this->trameMsg);
        loop.exec(QEventLoop::AllEvents|QEventLoop::WaitForMoreEvents);
        convertData32to16();
        QString idBadge = contenuBadge.at(0);
        materiel.setIdBadge(idBadge);

        materiel.setNomMateriel(contenuBadge.at(5));

        QDate dateControle = QDate::fromString(contenuBadge.at(6), "dd/MM/yyyy");
        materiel.setDateControle(dateControle);

        QDate newDateControle = QDate::fromString(contenuBadge.at(7), "dd/MM/yyyy");
        materiel.setNewDateControle(newDateControle);

        Type type = typeSrv->getByNomType(contenuBadge.at(8));
        materiel.setType(type);
    }else{
        materiel.setId(0);
    }
    deconnexion();
    return materiel;
}

bool PhysiqueIO::LecteurRFIDIOServiceImpl::ecrireBadge(Materiel materiel)
{
    int i;
    QEventLoop loop;
    connect(this, SIGNAL(dataOk(bool)), &loop,SLOT(quit()));
    QString param,nom,buf,type,buf2;
    connexion(ip, port);
    if(connexionEtat == true){
        contenuBadge.clear();
        nom = materiel.getNomMateriel();
        buf.sprintf("%16s",nom.toLatin1().data());
        contenuBadge.append(buf.toLatin1().toHex());
        contenuBadge.append(materiel.getDateControle().toString("dd/MM/yyyy      ").toLatin1().toHex());
        contenuBadge.append(materiel.getNewDateControle().toString("dd/MM/yyyy      ").toLatin1().toHex());
        type = materiel.getType().getNomType();
        buf2.sprintf("%16s",type.toLatin1().data());
        contenuBadge.append(buf2.toLatin1().toHex());

        for(i = 4; i < 8;i++){
            param.sprintf("%02x%s",i,contenuBadge.at(i-4).toLatin1().data());
            qWarning("param : %s",param.toLatin1().data());
            construireLigne(fctEcrire, param);
            qWarning("trame msg : %s",trameMsg.data());
            envoiTrame(this->trameMsg);
            loop.exec(QEventLoop::AllEvents|QEventLoop::WaitForMoreEvents);
        }
    }


    if(cmdRecu.at(0) == ACK){
        deconnexion();
        return true;
    }else{
        deconnexion();
        return false;
    }

}

void PhysiqueIO::LecteurRFIDIOServiceImpl::connexion(QString ip, int port)
{
    qWarning("fct connexion(ip,port)");
    tcpSocket.connectToHost(ip, port);
    if(!tcpSocket.waitForConnected(5000)){
        msgErreur = tcpSocket.errorString();
        qWarning("%s", msgErreur.toLatin1().data());
    }else{
        qWarning("connect to host OK");
    }

}

void PhysiqueIO::LecteurRFIDIOServiceImpl::deconnexion()
{
    qWarning("fct deconnexion()");
    tcpSocket.disconnectFromHost();

}


void PhysiqueIO::LecteurRFIDIOServiceImpl::construireLigne(QString noFonc, QString param)
{
    int i;
    unsigned char check;
    trameMsg.clear();
    trameMsg[0] = STX;
    trameMsg.append(noFonc);
    trameMsg.append(param);
    trameMsg[trameMsg.length()] = ETX;
    qWarning("checksum :");
    for(i=0, check=0; i< trameMsg.length(); i++){
        check ^= trameMsg[i];
//        qWarning("%x", check);
    }
    qWarning("checksum total = %x",check);
    trameMsg[i] = check;

}

void PhysiqueIO::LecteurRFIDIOServiceImpl::envoiTrame(QByteArray cmd)
{
    qWarning("Envoi :");
    for(int i=0; i< cmd.length(); i++){
        qWarning("%x", cmd.data()[i]);
    }
    if(!this->tcpSocket.write(cmd, cmd.length()) <= 0){
        qWarning("envoi effectuer");
        this->tcpSocket.flush();
    }else{
        qWarning("envoi non effectué");
    }
}

void PhysiqueIO::LecteurRFIDIOServiceImpl::lireTrame()
{
    QString s;
    QByteArray cmdRecu = getCmdRecu();
    msg.clear();
    switch(cmdRecu.data()[0]){
    case SYN:
            qWarning("[SYN] - Erreur");
        break;
    case ACK:
        qWarning("[ACK] - msg");
        for(int i = 6; i < cmdRecu.length() - 2; i++) {
            s.sprintf("%c", cmdRecu.data()[i]);
            msg.append(s);
        }
        break;
    case NAK:
            qWarning("[NAK] - ?");
        break;
    default:
        break;
    }
}

QByteArray PhysiqueIO::LecteurRFIDIOServiceImpl::getCmdRecu()
{
    return this->cmdRecu;
}

void PhysiqueIO::LecteurRFIDIOServiceImpl::convertData32to16()
{
    int i;
    QStringList list;

    for(i = 0; i < 512; i+=32){
        list.append(msg.mid(i,32)); //on parse en 16 Block de 32 carac
    }

//    for(i = 0;i < 16;i++){
//        qWarning("contenu List [%02d] %s",i ,list.at(i).toLatin1().data());
//    }

    contenuBadge.append(msg.left(8)); // on garde en hex l'id du badge
    for(i=0 ;i < list.length(); i++){
        QByteArray tab = QByteArray::fromHex(list.at(i).toLatin1());// on converti l' hex en Ascii
        contenuBadge.append(tab.data());
    }

    for(i = 0;i < 16;i++){
        qWarning("contenu convert[%02d] %s",i ,contenuBadge.at(i).toLatin1().data());
    }

}

void PhysiqueIO::LecteurRFIDIOServiceImpl::deconnexionOK()
{
    qWarning("deconnexion OK");
    this->connexionEtat = false;
}

void PhysiqueIO::LecteurRFIDIOServiceImpl::connexionOK()
{
    qWarning("connexion OK");
    this->connexionEtat = true;
}

void PhysiqueIO::LecteurRFIDIOServiceImpl::readDatagram()
{
    qWarning("lecture trame en cour");
    this->cmdRecu =this->tcpSocket.readAll();

    lireTrame();
     qWarning("%s",msg.toLatin1().data());
     emit dataOk(true);
}

void PhysiqueIO::LecteurRFIDIOServiceImpl::detectErreur()
{
    qWarning("erreur de trame");
     this->connexionEtat = false;
}
