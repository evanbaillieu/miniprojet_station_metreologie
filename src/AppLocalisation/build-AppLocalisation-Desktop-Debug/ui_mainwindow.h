/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionVoir;
    QAction *actionPar_type;
    QAction *actionPar_salle;
    QAction *actionPar_batiment;
    QAction *actionPar_nom;
    QAction *actionPar_atelier;
    QAction *actionAjouterSalle;
    QAction *actionModifierBatiment;
    QAction *actionModifierSalle;
    QAction *actionSupprimerBatiment;
    QAction *actionSupprimerSalle;
    QAction *actionPar_badge;
    QAction *actionPar_lieu;
    QAction *actionCreerBatiment;
    QAction *actionCreerSalle;
    QAction *actionSupprimerPortique;
    QAction *actionModifierPortique;
    QAction *actionCreerPortique;
    QAction *actionPar_Controle;
    QWidget *centralWidget;
    QWidget *formLayoutWidget;
    QFormLayout *layoutGauche;
    QWidget *formLayoutWidget_2;
    QFormLayout *layoutDroit;
    QMenuBar *menuBar;
    QMenu *menuPlan;
    QMenu *menuModifier;
    QMenu *menuSupprimer;
    QMenu *menuCr_er;
    QMenu *menuRechercher;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(993, 632);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/image/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionVoir = new QAction(MainWindow);
        actionVoir->setObjectName(QStringLiteral("actionVoir"));
        actionPar_type = new QAction(MainWindow);
        actionPar_type->setObjectName(QStringLiteral("actionPar_type"));
        actionPar_type->setCheckable(false);
        actionPar_salle = new QAction(MainWindow);
        actionPar_salle->setObjectName(QStringLiteral("actionPar_salle"));
        actionPar_batiment = new QAction(MainWindow);
        actionPar_batiment->setObjectName(QStringLiteral("actionPar_batiment"));
        actionPar_nom = new QAction(MainWindow);
        actionPar_nom->setObjectName(QStringLiteral("actionPar_nom"));
        actionPar_atelier = new QAction(MainWindow);
        actionPar_atelier->setObjectName(QStringLiteral("actionPar_atelier"));
        actionAjouterSalle = new QAction(MainWindow);
        actionAjouterSalle->setObjectName(QStringLiteral("actionAjouterSalle"));
        actionModifierBatiment = new QAction(MainWindow);
        actionModifierBatiment->setObjectName(QStringLiteral("actionModifierBatiment"));
        actionModifierSalle = new QAction(MainWindow);
        actionModifierSalle->setObjectName(QStringLiteral("actionModifierSalle"));
        actionSupprimerBatiment = new QAction(MainWindow);
        actionSupprimerBatiment->setObjectName(QStringLiteral("actionSupprimerBatiment"));
        actionSupprimerSalle = new QAction(MainWindow);
        actionSupprimerSalle->setObjectName(QStringLiteral("actionSupprimerSalle"));
        actionPar_badge = new QAction(MainWindow);
        actionPar_badge->setObjectName(QStringLiteral("actionPar_badge"));
        actionPar_lieu = new QAction(MainWindow);
        actionPar_lieu->setObjectName(QStringLiteral("actionPar_lieu"));
        actionCreerBatiment = new QAction(MainWindow);
        actionCreerBatiment->setObjectName(QStringLiteral("actionCreerBatiment"));
        actionCreerSalle = new QAction(MainWindow);
        actionCreerSalle->setObjectName(QStringLiteral("actionCreerSalle"));
        actionSupprimerPortique = new QAction(MainWindow);
        actionSupprimerPortique->setObjectName(QStringLiteral("actionSupprimerPortique"));
        actionModifierPortique = new QAction(MainWindow);
        actionModifierPortique->setObjectName(QStringLiteral("actionModifierPortique"));
        actionCreerPortique = new QAction(MainWindow);
        actionCreerPortique->setObjectName(QStringLiteral("actionCreerPortique"));
        actionPar_Controle = new QAction(MainWindow);
        actionPar_Controle->setObjectName(QStringLiteral("actionPar_Controle"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(9, 10, 171, 571));
        layoutGauche = new QFormLayout(formLayoutWidget);
        layoutGauche->setSpacing(6);
        layoutGauche->setContentsMargins(11, 11, 11, 11);
        layoutGauche->setObjectName(QStringLiteral("layoutGauche"));
        layoutGauche->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        layoutGauche->setContentsMargins(0, 0, 0, 0);
        formLayoutWidget_2 = new QWidget(centralWidget);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(190, 10, 791, 571));
        layoutDroit = new QFormLayout(formLayoutWidget_2);
        layoutDroit->setSpacing(6);
        layoutDroit->setContentsMargins(11, 11, 11, 11);
        layoutDroit->setObjectName(QStringLiteral("layoutDroit"));
        layoutDroit->setSizeConstraint(QLayout::SetDefaultConstraint);
        layoutDroit->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        layoutDroit->setRowWrapPolicy(QFormLayout::DontWrapRows);
        layoutDroit->setLabelAlignment(Qt::AlignJustify|Qt::AlignTop);
        layoutDroit->setFormAlignment(Qt::AlignJustify|Qt::AlignTop);
        layoutDroit->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 993, 19));
        menuPlan = new QMenu(menuBar);
        menuPlan->setObjectName(QStringLiteral("menuPlan"));
        menuModifier = new QMenu(menuPlan);
        menuModifier->setObjectName(QStringLiteral("menuModifier"));
        menuSupprimer = new QMenu(menuPlan);
        menuSupprimer->setObjectName(QStringLiteral("menuSupprimer"));
        menuCr_er = new QMenu(menuPlan);
        menuCr_er->setObjectName(QStringLiteral("menuCr_er"));
        menuRechercher = new QMenu(menuBar);
        menuRechercher->setObjectName(QStringLiteral("menuRechercher"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuPlan->menuAction());
        menuBar->addAction(menuRechercher->menuAction());
        menuPlan->addAction(actionVoir);
        menuPlan->addSeparator();
        menuPlan->addAction(menuCr_er->menuAction());
        menuPlan->addAction(menuModifier->menuAction());
        menuPlan->addAction(menuSupprimer->menuAction());
        menuModifier->addAction(actionModifierBatiment);
        menuModifier->addAction(actionModifierSalle);
        menuModifier->addAction(actionModifierPortique);
        menuSupprimer->addAction(actionSupprimerBatiment);
        menuSupprimer->addAction(actionSupprimerSalle);
        menuSupprimer->addAction(actionSupprimerPortique);
        menuCr_er->addAction(actionCreerBatiment);
        menuCr_er->addAction(actionCreerSalle);
        menuCr_er->addAction(actionCreerPortique);
        menuRechercher->addAction(actionPar_type);
        menuRechercher->addAction(actionPar_nom);
        menuRechercher->addAction(actionPar_badge);
        menuRechercher->addSeparator();
        menuRechercher->addAction(actionPar_lieu);
        menuRechercher->addSeparator();
        menuRechercher->addAction(actionPar_Controle);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Localisation", 0));
        actionVoir->setText(QApplication::translate("MainWindow", "Voir", 0));
        actionPar_type->setText(QApplication::translate("MainWindow", "Par type", 0));
        actionPar_salle->setText(QApplication::translate("MainWindow", "Par salle", 0));
        actionPar_batiment->setText(QApplication::translate("MainWindow", "Par batiment", 0));
        actionPar_nom->setText(QApplication::translate("MainWindow", "Par nom", 0));
        actionPar_atelier->setText(QApplication::translate("MainWindow", "Par atelier", 0));
        actionAjouterSalle->setText(QApplication::translate("MainWindow", "Salle", 0));
        actionModifierBatiment->setText(QApplication::translate("MainWindow", "Batiment", 0));
        actionModifierSalle->setText(QApplication::translate("MainWindow", "Salle", 0));
        actionSupprimerBatiment->setText(QApplication::translate("MainWindow", "Batiment", 0));
        actionSupprimerSalle->setText(QApplication::translate("MainWindow", "Salle", 0));
        actionPar_badge->setText(QApplication::translate("MainWindow", "Par badge", 0));
        actionPar_lieu->setText(QApplication::translate("MainWindow", "Par lieu", 0));
        actionCreerBatiment->setText(QApplication::translate("MainWindow", "Batiment", 0));
        actionCreerSalle->setText(QApplication::translate("MainWindow", "Salle", 0));
        actionSupprimerPortique->setText(QApplication::translate("MainWindow", "Portique", 0));
        actionModifierPortique->setText(QApplication::translate("MainWindow", "Portique", 0));
        actionCreerPortique->setText(QApplication::translate("MainWindow", "Portique", 0));
        actionPar_Controle->setText(QApplication::translate("MainWindow", "Par controle", 0));
        menuPlan->setTitle(QApplication::translate("MainWindow", "Plan", 0));
        menuModifier->setTitle(QApplication::translate("MainWindow", "Modifier", 0));
        menuSupprimer->setTitle(QApplication::translate("MainWindow", "Supprimer", 0));
        menuCr_er->setTitle(QApplication::translate("MainWindow", "Cr\303\251er", 0));
        menuRechercher->setTitle(QApplication::translate("MainWindow", "Rechercher", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
