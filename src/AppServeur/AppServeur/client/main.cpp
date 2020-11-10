#include <QCoreApplication>
#include "servertcp.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ServerTCP sTCP(&a);
    sTCP.lancement();
    return a.exec();
}
