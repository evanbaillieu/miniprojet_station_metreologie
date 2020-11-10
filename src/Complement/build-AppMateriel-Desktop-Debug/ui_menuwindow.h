/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QAction *actionVoirMateriel;
    QAction *actionType;
    QAction *actionAdmin;
    QWidget *centralwidget;
    QStackedWidget *stackedWidgetMain;
    QWidget *page1;
    QPushButton *pushButtonModifier_Menu;
    QPushButton *pushButtonAjouter_Menu;
    QPushButton *pushButtonSupprimer_Menu;
    QTableWidget *tableWidget;
    QPushButton *pushButtonLireBadge_Menu;
    QWidget *page2;
    QLabel *labelIdBadge_OperationMateriel;
    QLabel *labelNomMateriel_OperationMateriel;
    QLabel *labelType_OperationMateriel;
    QLineEdit *lineEditIdBadge_OperationMateriel;
    QLineEdit *lineEditNomMateriel_OperationMateriel;
    QComboBox *comboBoxType_OperationMateriel;
    QLabel *labelControle_OperationMateriel;
    QPushButton *pushButtonAjouter_OperationMateriel;
    QPushButton *pushButtonReset_OperationMateriel;
    QLabel *labelAjouterType_OperationMateriel;
    QDateEdit *dateEditControle_OperationMateriel;
    QPushButton *pushButtonModifier_OperationMateriel;
    QSpinBox *spinBoxNewDateControle;
    QLabel *labelNewDateControle;
    QWidget *page3;
    QPushButton *pushButtonValider_OperationType;
    QPushButton *pushButtonAnnuler_OperationType;
    QLabel *labelNomType_OperationType;
    QLineEdit *lineEditNomType_OperationType;
    QLabel *labelNomImage_OperationType;
    QLineEdit *lineEditNomImage_OperationType;
    QPushButton *pushButtonOpen_OperationType;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName(QStringLiteral("MenuWindow"));
        MenuWindow->resize(906, 528);
        MenuWindow->setStyleSheet(QStringLiteral(""));
        actionVoirMateriel = new QAction(MenuWindow);
        actionVoirMateriel->setObjectName(QStringLiteral("actionVoirMateriel"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ressources/images/voirInfo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVoirMateriel->setIcon(icon);
        actionType = new QAction(MenuWindow);
        actionType->setObjectName(QStringLiteral("actionType"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ressources/images/type.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionType->setIcon(icon1);
        actionAdmin = new QAction(MenuWindow);
        actionAdmin->setObjectName(QStringLiteral("actionAdmin"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/ressources/images/admin.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdmin->setIcon(icon2);
        centralwidget = new QWidget(MenuWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidgetMain = new QStackedWidget(centralwidget);
        stackedWidgetMain->setObjectName(QStringLiteral("stackedWidgetMain"));
        stackedWidgetMain->setEnabled(true);
        stackedWidgetMain->setGeometry(QRect(10, 0, 881, 461));
        QFont font;
        font.setPointSize(8);
        stackedWidgetMain->setFont(font);
        stackedWidgetMain->setMouseTracking(false);
        stackedWidgetMain->setAcceptDrops(false);
        stackedWidgetMain->setAutoFillBackground(false);
        page1 = new QWidget();
        page1->setObjectName(QStringLiteral("page1"));
        pushButtonModifier_Menu = new QPushButton(page1);
        pushButtonModifier_Menu->setObjectName(QStringLiteral("pushButtonModifier_Menu"));
        pushButtonModifier_Menu->setGeometry(QRect(640, 40, 221, 23));
        pushButtonAjouter_Menu = new QPushButton(page1);
        pushButtonAjouter_Menu->setObjectName(QStringLiteral("pushButtonAjouter_Menu"));
        pushButtonAjouter_Menu->setGeometry(QRect(0, 40, 251, 23));
        pushButtonSupprimer_Menu = new QPushButton(page1);
        pushButtonSupprimer_Menu->setObjectName(QStringLiteral("pushButtonSupprimer_Menu"));
        pushButtonSupprimer_Menu->setEnabled(true);
        pushButtonSupprimer_Menu->setGeometry(QRect(320, 40, 251, 23));
        tableWidget = new QTableWidget(page1);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem7);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(0, 70, 861, 351));
        tableWidget->setAutoFillBackground(false);
        tableWidget->setAutoScrollMargin(16);
        tableWidget->setShowGrid(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget->horizontalHeader()->setMinimumSectionSize(33);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        tableWidget->verticalHeader()->setMinimumSectionSize(19);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(true);
        pushButtonLireBadge_Menu = new QPushButton(page1);
        pushButtonLireBadge_Menu->setObjectName(QStringLiteral("pushButtonLireBadge_Menu"));
        pushButtonLireBadge_Menu->setGeometry(QRect(370, 430, 121, 23));
        stackedWidgetMain->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName(QStringLiteral("page2"));
        labelIdBadge_OperationMateriel = new QLabel(page2);
        labelIdBadge_OperationMateriel->setObjectName(QStringLiteral("labelIdBadge_OperationMateriel"));
        labelIdBadge_OperationMateriel->setGeometry(QRect(290, 10, 71, 21));
        labelNomMateriel_OperationMateriel = new QLabel(page2);
        labelNomMateriel_OperationMateriel->setObjectName(QStringLiteral("labelNomMateriel_OperationMateriel"));
        labelNomMateriel_OperationMateriel->setGeometry(QRect(270, 70, 101, 21));
        labelType_OperationMateriel = new QLabel(page2);
        labelType_OperationMateriel->setObjectName(QStringLiteral("labelType_OperationMateriel"));
        labelType_OperationMateriel->setGeometry(QRect(340, 100, 31, 21));
        lineEditIdBadge_OperationMateriel = new QLineEdit(page2);
        lineEditIdBadge_OperationMateriel->setObjectName(QStringLiteral("lineEditIdBadge_OperationMateriel"));
        lineEditIdBadge_OperationMateriel->setGeometry(QRect(380, 10, 131, 20));
        lineEditNomMateriel_OperationMateriel = new QLineEdit(page2);
        lineEditNomMateriel_OperationMateriel->setObjectName(QStringLiteral("lineEditNomMateriel_OperationMateriel"));
        lineEditNomMateriel_OperationMateriel->setGeometry(QRect(380, 70, 131, 20));
        comboBoxType_OperationMateriel = new QComboBox(page2);
        comboBoxType_OperationMateriel->setObjectName(QStringLiteral("comboBoxType_OperationMateriel"));
        comboBoxType_OperationMateriel->setGeometry(QRect(380, 100, 131, 22));
        labelControle_OperationMateriel = new QLabel(page2);
        labelControle_OperationMateriel->setObjectName(QStringLiteral("labelControle_OperationMateriel"));
        labelControle_OperationMateriel->setGeometry(QRect(270, 40, 101, 21));
        pushButtonAjouter_OperationMateriel = new QPushButton(page2);
        pushButtonAjouter_OperationMateriel->setObjectName(QStringLiteral("pushButtonAjouter_OperationMateriel"));
        pushButtonAjouter_OperationMateriel->setGeometry(QRect(410, 160, 75, 23));
        pushButtonReset_OperationMateriel = new QPushButton(page2);
        pushButtonReset_OperationMateriel->setObjectName(QStringLiteral("pushButtonReset_OperationMateriel"));
        pushButtonReset_OperationMateriel->setGeometry(QRect(330, 160, 75, 23));
        labelAjouterType_OperationMateriel = new QLabel(page2);
        labelAjouterType_OperationMateriel->setObjectName(QStringLiteral("labelAjouterType_OperationMateriel"));
        labelAjouterType_OperationMateriel->setGeometry(QRect(380, 120, 181, 21));
        labelAjouterType_OperationMateriel->setOpenExternalLinks(false);
        dateEditControle_OperationMateriel = new QDateEdit(page2);
        dateEditControle_OperationMateriel->setObjectName(QStringLiteral("dateEditControle_OperationMateriel"));
        dateEditControle_OperationMateriel->setEnabled(true);
        dateEditControle_OperationMateriel->setGeometry(QRect(380, 40, 131, 22));
        dateEditControle_OperationMateriel->setCalendarPopup(true);
        dateEditControle_OperationMateriel->setDate(QDate(2000, 1, 1));
        pushButtonModifier_OperationMateriel = new QPushButton(page2);
        pushButtonModifier_OperationMateriel->setObjectName(QStringLiteral("pushButtonModifier_OperationMateriel"));
        pushButtonModifier_OperationMateriel->setGeometry(QRect(490, 160, 75, 23));
        spinBoxNewDateControle = new QSpinBox(page2);
        spinBoxNewDateControle->setObjectName(QStringLiteral("spinBoxNewDateControle"));
        spinBoxNewDateControle->setGeometry(QRect(520, 100, 51, 21));
        spinBoxNewDateControle->setMinimum(1);
        spinBoxNewDateControle->setMaximum(999);
        labelNewDateControle = new QLabel(page2);
        labelNewDateControle->setObjectName(QStringLiteral("labelNewDateControle"));
        labelNewDateControle->setGeometry(QRect(520, 70, 201, 16));
        stackedWidgetMain->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName(QStringLiteral("page3"));
        pushButtonValider_OperationType = new QPushButton(page3);
        pushButtonValider_OperationType->setObjectName(QStringLiteral("pushButtonValider_OperationType"));
        pushButtonValider_OperationType->setGeometry(QRect(360, 120, 75, 23));
        pushButtonAnnuler_OperationType = new QPushButton(page3);
        pushButtonAnnuler_OperationType->setObjectName(QStringLiteral("pushButtonAnnuler_OperationType"));
        pushButtonAnnuler_OperationType->setGeometry(QRect(460, 120, 75, 23));
        labelNomType_OperationType = new QLabel(page3);
        labelNomType_OperationType->setObjectName(QStringLiteral("labelNomType_OperationType"));
        labelNomType_OperationType->setGeometry(QRect(400, 10, 81, 21));
        lineEditNomType_OperationType = new QLineEdit(page3);
        lineEditNomType_OperationType->setObjectName(QStringLiteral("lineEditNomType_OperationType"));
        lineEditNomType_OperationType->setGeometry(QRect(370, 30, 131, 20));
        labelNomImage_OperationType = new QLabel(page3);
        labelNomImage_OperationType->setObjectName(QStringLiteral("labelNomImage_OperationType"));
        labelNomImage_OperationType->setGeometry(QRect(400, 70, 81, 21));
        lineEditNomImage_OperationType = new QLineEdit(page3);
        lineEditNomImage_OperationType->setObjectName(QStringLiteral("lineEditNomImage_OperationType"));
        lineEditNomImage_OperationType->setGeometry(QRect(320, 90, 251, 20));
        pushButtonOpen_OperationType = new QPushButton(page3);
        pushButtonOpen_OperationType->setObjectName(QStringLiteral("pushButtonOpen_OperationType"));
        pushButtonOpen_OperationType->setGeometry(QRect(570, 90, 21, 21));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/ressources/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonOpen_OperationType->setIcon(icon3);
        stackedWidgetMain->addWidget(page3);
        MenuWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MenuWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 906, 20));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        MenuWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MenuWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setIconSize(QSize(30, 30));
        MenuWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionVoirMateriel);
        menuFichier->addAction(actionType);
        menuFichier->addAction(actionAdmin);
        toolBar->addAction(actionVoirMateriel);
        toolBar->addSeparator();
        toolBar->addAction(actionType);
        toolBar->addSeparator();
        toolBar->addAction(actionAdmin);

        retranslateUi(MenuWindow);

        stackedWidgetMain->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MenuWindow)
    {
        MenuWindow->setWindowTitle(QApplication::translate("MenuWindow", "MainWindow", 0));
        actionVoirMateriel->setText(QApplication::translate("MenuWindow", "Voir le mat\303\251riel", 0));
        actionType->setText(QApplication::translate("MenuWindow", "Ajouter un type", 0));
        actionAdmin->setText(QApplication::translate("MenuWindow", "G\303\251rer l'administration", 0));
        pushButtonModifier_Menu->setText(QApplication::translate("MenuWindow", "Modifier", 0));
        pushButtonAjouter_Menu->setText(QApplication::translate("MenuWindow", "Ajouter", 0));
        pushButtonSupprimer_Menu->setText(QApplication::translate("MenuWindow", "Supprimer", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MenuWindow", "Id du badge", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MenuWindow", "Nom", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MenuWindow", "Futur controle", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MenuWindow", "Type", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MenuWindow", "Materiel", 0));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        pushButtonLireBadge_Menu->setText(QApplication::translate("MenuWindow", "Lire le badge", 0));
        labelIdBadge_OperationMateriel->setText(QApplication::translate("MenuWindow", "Id du badge:", 0));
        labelNomMateriel_OperationMateriel->setText(QApplication::translate("MenuWindow", "Nom du materiel:", 0));
        labelType_OperationMateriel->setText(QApplication::translate("MenuWindow", "Type:", 0));
        labelControle_OperationMateriel->setText(QApplication::translate("MenuWindow", "Dernier contr\303\264le:", 0));
        pushButtonAjouter_OperationMateriel->setText(QApplication::translate("MenuWindow", "Ajouter", 0));
        pushButtonReset_OperationMateriel->setText(QApplication::translate("MenuWindow", "Reset", 0));
        labelAjouterType_OperationMateriel->setText(QApplication::translate("MenuWindow", "<a href=\"#\">Besoin de rajouter un type?</a>", 0));
        dateEditControle_OperationMateriel->setDisplayFormat(QApplication::translate("MenuWindow", "dd/MM/yyyy", 0));
        pushButtonModifier_OperationMateriel->setText(QApplication::translate("MenuWindow", "Modifier", 0));
        labelNewDateControle->setText(QApplication::translate("MenuWindow", "Nombre de jour entre 2 contr\303\264les:", 0));
        pushButtonValider_OperationType->setText(QApplication::translate("MenuWindow", "Valider", 0));
        pushButtonAnnuler_OperationType->setText(QApplication::translate("MenuWindow", "Annuler", 0));
        labelNomType_OperationType->setText(QApplication::translate("MenuWindow", "Nom du type", 0));
        labelNomImage_OperationType->setText(QApplication::translate("MenuWindow", "Nom d'image", 0));
        pushButtonOpen_OperationType->setText(QString());
        menuFichier->setTitle(QApplication::translate("MenuWindow", "Menu", 0));
        toolBar->setWindowTitle(QApplication::translate("MenuWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
