/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppLocalisation/client/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[63];
    char stringdata[1580];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "rechercheParType"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 15), // "rechercheParNom"
QT_MOC_LITERAL(4, 45, 17), // "rechercheParBadge"
QT_MOC_LITERAL(5, 63, 20), // "rechercheParBatiment"
QT_MOC_LITERAL(6, 84, 17), // "rechercheParSalle"
QT_MOC_LITERAL(7, 102, 26), // "rechercheParControleValide"
QT_MOC_LITERAL(8, 129, 29), // "rechercheParControleNonValide"
QT_MOC_LITERAL(9, 159, 19), // "rechercheCheminPlan"
QT_MOC_LITERAL(10, 179, 13), // "recupererPlan"
QT_MOC_LITERAL(11, 193, 11), // "nomBatiment"
QT_MOC_LITERAL(12, 205, 23), // "prendreCoordonneesSalle"
QT_MOC_LITERAL(13, 229, 26), // "prendreCoordonneesPortique"
QT_MOC_LITERAL(14, 256, 13), // "creerBatiment"
QT_MOC_LITERAL(15, 270, 16), // "modifierBatiment"
QT_MOC_LITERAL(16, 287, 17), // "supprimerBatiment"
QT_MOC_LITERAL(17, 305, 10), // "creerSalle"
QT_MOC_LITERAL(18, 316, 13), // "modifierSalle"
QT_MOC_LITERAL(19, 330, 14), // "supprimerSalle"
QT_MOC_LITERAL(20, 345, 13), // "creerPortique"
QT_MOC_LITERAL(21, 359, 16), // "modifierPortique"
QT_MOC_LITERAL(22, 376, 17), // "supprimerPortique"
QT_MOC_LITERAL(23, 394, 21), // "recupererInfoBatiment"
QT_MOC_LITERAL(24, 416, 7), // "contenu"
QT_MOC_LITERAL(25, 424, 18), // "recupererInfoSalle"
QT_MOC_LITERAL(26, 443, 21), // "recupererInfoPortique"
QT_MOC_LITERAL(27, 465, 12), // "resultatVoir"
QT_MOC_LITERAL(28, 478, 19), // "resultatVoirEtTimer"
QT_MOC_LITERAL(29, 498, 31), // "affichageListeMaterielDansSalle"
QT_MOC_LITERAL(30, 530, 31), // "indexChangedComboBoxNomMateriel"
QT_MOC_LITERAL(31, 562, 30), // "textChangedLineEditNomMateriel"
QT_MOC_LITERAL(32, 593, 27), // "indexChangedComboBoxIdBadge"
QT_MOC_LITERAL(33, 621, 26), // "textChangedLineEditIdBadge"
QT_MOC_LITERAL(34, 648, 36), // "indexChangedComboBoxNomBatime..."
QT_MOC_LITERAL(35, 685, 44), // "indexChangedComboBoxNomBatime..."
QT_MOC_LITERAL(36, 730, 48), // "indexChangedComboBoxNomBatime..."
QT_MOC_LITERAL(37, 779, 30), // "textChangedLineEditNomBatiment"
QT_MOC_LITERAL(38, 810, 28), // "indexChangedComboBoxNumSalle"
QT_MOC_LITERAL(39, 839, 27), // "textChangedLineEditNumSalle"
QT_MOC_LITERAL(40, 867, 37), // "indexChangedComboBoxNumSalleP..."
QT_MOC_LITERAL(41, 905, 36), // "textChangedLineEditNumSallePo..."
QT_MOC_LITERAL(42, 942, 37), // "indexChangedComboBoxNumSalleP..."
QT_MOC_LITERAL(43, 980, 36), // "textChangedLineEditNumSallePo..."
QT_MOC_LITERAL(44, 1017, 29), // "indexChangedComboBoxIpLecteur"
QT_MOC_LITERAL(45, 1047, 28), // "textChangedLineEditIpLecteur"
QT_MOC_LITERAL(46, 1076, 10), // "clickTable"
QT_MOC_LITERAL(47, 1087, 15), // "situerSurLePlan"
QT_MOC_LITERAL(48, 1103, 27), // "on_actionPar_type_triggered"
QT_MOC_LITERAL(49, 1131, 26), // "on_actionPar_nom_triggered"
QT_MOC_LITERAL(50, 1158, 28), // "on_actionPar_badge_triggered"
QT_MOC_LITERAL(51, 1187, 27), // "on_actionPar_lieu_triggered"
QT_MOC_LITERAL(52, 1215, 31), // "on_actionPar_Controle_triggered"
QT_MOC_LITERAL(53, 1247, 32), // "on_actionCreerBatiment_triggered"
QT_MOC_LITERAL(54, 1280, 29), // "on_actionCreerSalle_triggered"
QT_MOC_LITERAL(55, 1310, 32), // "on_actionCreerPortique_triggered"
QT_MOC_LITERAL(56, 1343, 35), // "on_actionModifierBatiment_tri..."
QT_MOC_LITERAL(57, 1379, 32), // "on_actionModifierSalle_triggered"
QT_MOC_LITERAL(58, 1412, 35), // "on_actionModifierPortique_tri..."
QT_MOC_LITERAL(59, 1448, 36), // "on_actionSupprimerBatiment_tr..."
QT_MOC_LITERAL(60, 1485, 33), // "on_actionSupprimerSalle_trigg..."
QT_MOC_LITERAL(61, 1519, 36), // "on_actionSupprimerPortique_tr..."
QT_MOC_LITERAL(62, 1556, 23) // "on_actionVoir_triggered"

    },
    "MainWindow\0rechercheParType\0\0"
    "rechercheParNom\0rechercheParBadge\0"
    "rechercheParBatiment\0rechercheParSalle\0"
    "rechercheParControleValide\0"
    "rechercheParControleNonValide\0"
    "rechercheCheminPlan\0recupererPlan\0"
    "nomBatiment\0prendreCoordonneesSalle\0"
    "prendreCoordonneesPortique\0creerBatiment\0"
    "modifierBatiment\0supprimerBatiment\0"
    "creerSalle\0modifierSalle\0supprimerSalle\0"
    "creerPortique\0modifierPortique\0"
    "supprimerPortique\0recupererInfoBatiment\0"
    "contenu\0recupererInfoSalle\0"
    "recupererInfoPortique\0resultatVoir\0"
    "resultatVoirEtTimer\0affichageListeMaterielDansSalle\0"
    "indexChangedComboBoxNomMateriel\0"
    "textChangedLineEditNomMateriel\0"
    "indexChangedComboBoxIdBadge\0"
    "textChangedLineEditIdBadge\0"
    "indexChangedComboBoxNomBatimentSalle\0"
    "indexChangedComboBoxNomBatimentCreerPortique\0"
    "indexChangedComboBoxNomBatimentSupprimerPortique\0"
    "textChangedLineEditNomBatiment\0"
    "indexChangedComboBoxNumSalle\0"
    "textChangedLineEditNumSalle\0"
    "indexChangedComboBoxNumSallePortique1\0"
    "textChangedLineEditNumSallePortique1\0"
    "indexChangedComboBoxNumSallePortique2\0"
    "textChangedLineEditNumSallePortique2\0"
    "indexChangedComboBoxIpLecteur\0"
    "textChangedLineEditIpLecteur\0clickTable\0"
    "situerSurLePlan\0on_actionPar_type_triggered\0"
    "on_actionPar_nom_triggered\0"
    "on_actionPar_badge_triggered\0"
    "on_actionPar_lieu_triggered\0"
    "on_actionPar_Controle_triggered\0"
    "on_actionCreerBatiment_triggered\0"
    "on_actionCreerSalle_triggered\0"
    "on_actionCreerPortique_triggered\0"
    "on_actionModifierBatiment_triggered\0"
    "on_actionModifierSalle_triggered\0"
    "on_actionModifierPortique_triggered\0"
    "on_actionSupprimerBatiment_triggered\0"
    "on_actionSupprimerSalle_triggered\0"
    "on_actionSupprimerPortique_triggered\0"
    "on_actionVoir_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      59,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  309,    2, 0x08 /* Private */,
       3,    0,  310,    2, 0x08 /* Private */,
       4,    0,  311,    2, 0x08 /* Private */,
       5,    0,  312,    2, 0x08 /* Private */,
       6,    0,  313,    2, 0x08 /* Private */,
       7,    0,  314,    2, 0x08 /* Private */,
       8,    0,  315,    2, 0x08 /* Private */,
       9,    0,  316,    2, 0x08 /* Private */,
      10,    1,  317,    2, 0x08 /* Private */,
      12,    0,  320,    2, 0x08 /* Private */,
      13,    0,  321,    2, 0x08 /* Private */,
      14,    0,  322,    2, 0x08 /* Private */,
      15,    0,  323,    2, 0x08 /* Private */,
      16,    0,  324,    2, 0x08 /* Private */,
      17,    0,  325,    2, 0x08 /* Private */,
      18,    0,  326,    2, 0x08 /* Private */,
      19,    0,  327,    2, 0x08 /* Private */,
      20,    0,  328,    2, 0x08 /* Private */,
      21,    0,  329,    2, 0x08 /* Private */,
      22,    0,  330,    2, 0x08 /* Private */,
      23,    1,  331,    2, 0x08 /* Private */,
      25,    1,  334,    2, 0x08 /* Private */,
      26,    1,  337,    2, 0x08 /* Private */,
      27,    0,  340,    2, 0x08 /* Private */,
      28,    0,  341,    2, 0x08 /* Private */,
      29,    0,  342,    2, 0x08 /* Private */,
      30,    1,  343,    2, 0x08 /* Private */,
      31,    1,  346,    2, 0x08 /* Private */,
      32,    1,  349,    2, 0x08 /* Private */,
      33,    1,  352,    2, 0x08 /* Private */,
      34,    1,  355,    2, 0x08 /* Private */,
      35,    1,  358,    2, 0x08 /* Private */,
      36,    1,  361,    2, 0x08 /* Private */,
      37,    1,  364,    2, 0x08 /* Private */,
      38,    1,  367,    2, 0x08 /* Private */,
      39,    1,  370,    2, 0x08 /* Private */,
      40,    1,  373,    2, 0x08 /* Private */,
      41,    1,  376,    2, 0x08 /* Private */,
      42,    1,  379,    2, 0x08 /* Private */,
      43,    1,  382,    2, 0x08 /* Private */,
      44,    1,  385,    2, 0x08 /* Private */,
      45,    1,  388,    2, 0x08 /* Private */,
      46,    1,  391,    2, 0x08 /* Private */,
      47,    0,  394,    2, 0x08 /* Private */,
      48,    0,  395,    2, 0x08 /* Private */,
      49,    0,  396,    2, 0x08 /* Private */,
      50,    0,  397,    2, 0x08 /* Private */,
      51,    0,  398,    2, 0x08 /* Private */,
      52,    0,  399,    2, 0x08 /* Private */,
      53,    0,  400,    2, 0x08 /* Private */,
      54,    0,  401,    2, 0x08 /* Private */,
      55,    0,  402,    2, 0x08 /* Private */,
      56,    0,  403,    2, 0x08 /* Private */,
      57,    0,  404,    2, 0x08 /* Private */,
      58,    0,  405,    2, 0x08 /* Private */,
      59,    0,  406,    2, 0x08 /* Private */,
      60,    0,  407,    2, 0x08 /* Private */,
      61,    0,  408,    2, 0x08 /* Private */,
      62,    0,  409,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->rechercheParType(); break;
        case 1: _t->rechercheParNom(); break;
        case 2: _t->rechercheParBadge(); break;
        case 3: _t->rechercheParBatiment(); break;
        case 4: _t->rechercheParSalle(); break;
        case 5: _t->rechercheParControleValide(); break;
        case 6: _t->rechercheParControleNonValide(); break;
        case 7: _t->rechercheCheminPlan(); break;
        case 8: _t->recupererPlan((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->prendreCoordonneesSalle(); break;
        case 10: _t->prendreCoordonneesPortique(); break;
        case 11: _t->creerBatiment(); break;
        case 12: _t->modifierBatiment(); break;
        case 13: _t->supprimerBatiment(); break;
        case 14: _t->creerSalle(); break;
        case 15: _t->modifierSalle(); break;
        case 16: _t->supprimerSalle(); break;
        case 17: _t->creerPortique(); break;
        case 18: _t->modifierPortique(); break;
        case 19: _t->supprimerPortique(); break;
        case 20: _t->recupererInfoBatiment((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->recupererInfoSalle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: _t->recupererInfoPortique((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->resultatVoir(); break;
        case 24: _t->resultatVoirEtTimer(); break;
        case 25: _t->affichageListeMaterielDansSalle(); break;
        case 26: _t->indexChangedComboBoxNomMateriel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->textChangedLineEditNomMateriel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->indexChangedComboBoxIdBadge((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: _t->textChangedLineEditIdBadge((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: _t->indexChangedComboBoxNomBatimentSalle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 31: _t->indexChangedComboBoxNomBatimentCreerPortique((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 32: _t->indexChangedComboBoxNomBatimentSupprimerPortique((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 33: _t->textChangedLineEditNomBatiment((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 34: _t->indexChangedComboBoxNumSalle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 35: _t->textChangedLineEditNumSalle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 36: _t->indexChangedComboBoxNumSallePortique1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 37: _t->textChangedLineEditNumSallePortique1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 38: _t->indexChangedComboBoxNumSallePortique2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 39: _t->textChangedLineEditNumSallePortique2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 40: _t->indexChangedComboBoxIpLecteur((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 41: _t->textChangedLineEditIpLecteur((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 42: _t->clickTable((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 43: _t->situerSurLePlan(); break;
        case 44: _t->on_actionPar_type_triggered(); break;
        case 45: _t->on_actionPar_nom_triggered(); break;
        case 46: _t->on_actionPar_badge_triggered(); break;
        case 47: _t->on_actionPar_lieu_triggered(); break;
        case 48: _t->on_actionPar_Controle_triggered(); break;
        case 49: _t->on_actionCreerBatiment_triggered(); break;
        case 50: _t->on_actionCreerSalle_triggered(); break;
        case 51: _t->on_actionCreerPortique_triggered(); break;
        case 52: _t->on_actionModifierBatiment_triggered(); break;
        case 53: _t->on_actionModifierSalle_triggered(); break;
        case 54: _t->on_actionModifierPortique_triggered(); break;
        case 55: _t->on_actionSupprimerBatiment_triggered(); break;
        case 56: _t->on_actionSupprimerSalle_triggered(); break;
        case 57: _t->on_actionSupprimerPortique_triggered(); break;
        case 58: _t->on_actionVoir_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 59)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 59;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 59)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 59;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
