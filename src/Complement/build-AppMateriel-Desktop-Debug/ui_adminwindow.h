/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonAddUser;
    QPushButton *pushButtonEdit;
    QPushButton *pushButtonDelete;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QLabel *labelLogin_Seach;
    QLineEdit *lineEditLogin_Seach;
    QPushButton *pushButtonValid_Seach;
    QWidget *page2;
    QPushButton *pushButtonValid_GetAll;
    QSpinBox *spinBoxPage_GetAll;
    QSpinBox *spinBoxElement_GetAll;
    QLabel *labelPage_GetAll;
    QLabel *labelElement_GetAll;
    QWidget *page3;
    QPushButton *pushButtonValid_AddUser;
    QLineEdit *lineEditConfirm_AddUser;
    QLineEdit *lineEditPassword_AddUser;
    QLineEdit *lineEditLogin_AddUser;
    QLabel *labelLogin_AddUser;
    QLabel *labelPassword_AddUser;
    QLabel *labelConfirm_AddUser;
    QWidget *page4;
    QLineEdit *lineEditOldPassword_Edit;
    QLineEdit *lineEditNewLogin_Edit;
    QLineEdit *lineEditNewPassword_Edit;
    QLineEdit *lineEditConfirm_Edit;
    QPushButton *pushButtonValid_Edit;
    QLabel *labelOldPassword_Edit;
    QLabel *labelNewLogin_Edit;
    QLabel *labelNewPassword_Edit;
    QLabel *labelConfirm_Edit;
    QWidget *page5;
    QLineEdit *lineEditPassword_Delete;
    QPushButton *pushButtonValid_Delete;
    QLabel *labelPassword_Delete;
    QWidget *page6;
    QLabel *label;
    QPushButton *pushButtonGetAll;
    QPushButton *pushButtonSearch;
    QListWidget *listWidget;
    QMenuBar *menubar;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QStringLiteral("AdminWindow"));
        AdminWindow->resize(671, 442);
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButtonAddUser = new QPushButton(centralwidget);
        pushButtonAddUser->setObjectName(QStringLiteral("pushButtonAddUser"));
        pushButtonAddUser->setGeometry(QRect(24, 10, 91, 23));
        pushButtonEdit = new QPushButton(centralwidget);
        pushButtonEdit->setObjectName(QStringLiteral("pushButtonEdit"));
        pushButtonEdit->setGeometry(QRect(124, 10, 111, 23));
        pushButtonDelete = new QPushButton(centralwidget);
        pushButtonDelete->setObjectName(QStringLiteral("pushButtonDelete"));
        pushButtonDelete->setGeometry(QRect(244, 10, 121, 23));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 40, 651, 91));
        page1 = new QWidget();
        page1->setObjectName(QStringLiteral("page1"));
        labelLogin_Seach = new QLabel(page1);
        labelLogin_Seach->setObjectName(QStringLiteral("labelLogin_Seach"));
        labelLogin_Seach->setGeometry(QRect(310, 0, 46, 20));
        lineEditLogin_Seach = new QLineEdit(page1);
        lineEditLogin_Seach->setObjectName(QStringLiteral("lineEditLogin_Seach"));
        lineEditLogin_Seach->setGeometry(QRect(270, 20, 113, 20));
        pushButtonValid_Seach = new QPushButton(page1);
        pushButtonValid_Seach->setObjectName(QStringLiteral("pushButtonValid_Seach"));
        pushButtonValid_Seach->setGeometry(QRect(290, 40, 75, 23));
        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName(QStringLiteral("page2"));
        pushButtonValid_GetAll = new QPushButton(page2);
        pushButtonValid_GetAll->setObjectName(QStringLiteral("pushButtonValid_GetAll"));
        pushButtonValid_GetAll->setGeometry(QRect(280, 70, 75, 23));
        spinBoxPage_GetAll = new QSpinBox(page2);
        spinBoxPage_GetAll->setObjectName(QStringLiteral("spinBoxPage_GetAll"));
        spinBoxPage_GetAll->setGeometry(QRect(290, 10, 42, 22));
        spinBoxPage_GetAll->setMinimum(1);
        spinBoxPage_GetAll->setMaximum(100);
        spinBoxElement_GetAll = new QSpinBox(page2);
        spinBoxElement_GetAll->setObjectName(QStringLiteral("spinBoxElement_GetAll"));
        spinBoxElement_GetAll->setGeometry(QRect(290, 40, 42, 22));
        spinBoxElement_GetAll->setMinimum(1);
        spinBoxElement_GetAll->setMaximum(100);
        labelPage_GetAll = new QLabel(page2);
        labelPage_GetAll->setObjectName(QStringLiteral("labelPage_GetAll"));
        labelPage_GetAll->setGeometry(QRect(250, 10, 46, 21));
        labelElement_GetAll = new QLabel(page2);
        labelElement_GetAll->setObjectName(QStringLiteral("labelElement_GetAll"));
        labelElement_GetAll->setGeometry(QRect(230, 40, 51, 21));
        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName(QStringLiteral("page3"));
        pushButtonValid_AddUser = new QPushButton(page3);
        pushButtonValid_AddUser->setObjectName(QStringLiteral("pushButtonValid_AddUser"));
        pushButtonValid_AddUser->setGeometry(QRect(70, 220, 75, 23));
        lineEditConfirm_AddUser = new QLineEdit(page3);
        lineEditConfirm_AddUser->setObjectName(QStringLiteral("lineEditConfirm_AddUser"));
        lineEditConfirm_AddUser->setGeometry(QRect(442, 30, 181, 20));
        lineEditPassword_AddUser = new QLineEdit(page3);
        lineEditPassword_AddUser->setObjectName(QStringLiteral("lineEditPassword_AddUser"));
        lineEditPassword_AddUser->setGeometry(QRect(240, 30, 181, 20));
        lineEditLogin_AddUser = new QLineEdit(page3);
        lineEditLogin_AddUser->setObjectName(QStringLiteral("lineEditLogin_AddUser"));
        lineEditLogin_AddUser->setGeometry(QRect(10, 30, 211, 20));
        labelLogin_AddUser = new QLabel(page3);
        labelLogin_AddUser->setObjectName(QStringLiteral("labelLogin_AddUser"));
        labelLogin_AddUser->setGeometry(QRect(80, 10, 46, 21));
        labelPassword_AddUser = new QLabel(page3);
        labelPassword_AddUser->setObjectName(QStringLiteral("labelPassword_AddUser"));
        labelPassword_AddUser->setGeometry(QRect(310, 10, 61, 21));
        labelConfirm_AddUser = new QLabel(page3);
        labelConfirm_AddUser->setObjectName(QStringLiteral("labelConfirm_AddUser"));
        labelConfirm_AddUser->setGeometry(QRect(510, 10, 111, 20));
        stackedWidget->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName(QStringLiteral("page4"));
        lineEditOldPassword_Edit = new QLineEdit(page4);
        lineEditOldPassword_Edit->setObjectName(QStringLiteral("lineEditOldPassword_Edit"));
        lineEditOldPassword_Edit->setGeometry(QRect(0, 40, 113, 20));
        lineEditNewLogin_Edit = new QLineEdit(page4);
        lineEditNewLogin_Edit->setObjectName(QStringLiteral("lineEditNewLogin_Edit"));
        lineEditNewLogin_Edit->setGeometry(QRect(180, 40, 113, 20));
        lineEditNewPassword_Edit = new QLineEdit(page4);
        lineEditNewPassword_Edit->setObjectName(QStringLiteral("lineEditNewPassword_Edit"));
        lineEditNewPassword_Edit->setGeometry(QRect(350, 40, 113, 20));
        lineEditConfirm_Edit = new QLineEdit(page4);
        lineEditConfirm_Edit->setObjectName(QStringLiteral("lineEditConfirm_Edit"));
        lineEditConfirm_Edit->setGeometry(QRect(530, 40, 113, 20));
        pushButtonValid_Edit = new QPushButton(page4);
        pushButtonValid_Edit->setObjectName(QStringLiteral("pushButtonValid_Edit"));
        pushButtonValid_Edit->setGeometry(QRect(280, 70, 75, 23));
        labelOldPassword_Edit = new QLabel(page4);
        labelOldPassword_Edit->setObjectName(QStringLiteral("labelOldPassword_Edit"));
        labelOldPassword_Edit->setGeometry(QRect(10, 20, 91, 21));
        labelNewLogin_Edit = new QLabel(page4);
        labelNewLogin_Edit->setObjectName(QStringLiteral("labelNewLogin_Edit"));
        labelNewLogin_Edit->setGeometry(QRect(210, 21, 71, 20));
        labelNewPassword_Edit = new QLabel(page4);
        labelNewPassword_Edit->setObjectName(QStringLiteral("labelNewPassword_Edit"));
        labelNewPassword_Edit->setGeometry(QRect(360, 20, 91, 21));
        labelConfirm_Edit = new QLabel(page4);
        labelConfirm_Edit->setObjectName(QStringLiteral("labelConfirm_Edit"));
        labelConfirm_Edit->setGeometry(QRect(530, 20, 141, 21));
        stackedWidget->addWidget(page4);
        page5 = new QWidget();
        page5->setObjectName(QStringLiteral("page5"));
        lineEditPassword_Delete = new QLineEdit(page5);
        lineEditPassword_Delete->setObjectName(QStringLiteral("lineEditPassword_Delete"));
        lineEditPassword_Delete->setGeometry(QRect(280, 30, 113, 20));
        pushButtonValid_Delete = new QPushButton(page5);
        pushButtonValid_Delete->setObjectName(QStringLiteral("pushButtonValid_Delete"));
        pushButtonValid_Delete->setGeometry(QRect(300, 50, 75, 23));
        labelPassword_Delete = new QLabel(page5);
        labelPassword_Delete->setObjectName(QStringLiteral("labelPassword_Delete"));
        labelPassword_Delete->setGeometry(QRect(310, 10, 61, 21));
        stackedWidget->addWidget(page5);
        page6 = new QWidget();
        page6->setObjectName(QStringLiteral("page6"));
        label = new QLabel(page6);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(260, 30, 131, 20));
        stackedWidget->addWidget(page6);
        pushButtonGetAll = new QPushButton(centralwidget);
        pushButtonGetAll->setObjectName(QStringLiteral("pushButtonGetAll"));
        pushButtonGetAll->setGeometry(QRect(374, 10, 121, 23));
        pushButtonSearch = new QPushButton(centralwidget);
        pushButtonSearch->setObjectName(QStringLiteral("pushButtonSearch"));
        pushButtonSearch->setGeometry(QRect(504, 10, 131, 23));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 140, 621, 251));
        AdminWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 671, 20));
        AdminWindow->setMenuBar(menubar);

        retranslateUi(AdminWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QApplication::translate("AdminWindow", "MainWindow", 0));
        pushButtonAddUser->setText(QApplication::translate("AdminWindow", "Add User", 0));
        pushButtonEdit->setText(QApplication::translate("AdminWindow", "Edit", 0));
        pushButtonDelete->setText(QApplication::translate("AdminWindow", "Delete", 0));
        labelLogin_Seach->setText(QApplication::translate("AdminWindow", "Login", 0));
        pushButtonValid_Seach->setText(QApplication::translate("AdminWindow", "Valid", 0));
        pushButtonValid_GetAll->setText(QApplication::translate("AdminWindow", "Valid", 0));
        labelPage_GetAll->setText(QApplication::translate("AdminWindow", "Page", 0));
        labelElement_GetAll->setText(QApplication::translate("AdminWindow", "\303\211l\303\251ments", 0));
        pushButtonValid_AddUser->setText(QApplication::translate("AdminWindow", "Valid", 0));
        labelLogin_AddUser->setText(QApplication::translate("AdminWindow", "Login", 0));
        labelPassword_AddUser->setText(QApplication::translate("AdminWindow", "Password", 0));
        labelConfirm_AddUser->setText(QApplication::translate("AdminWindow", "Confirm Password", 0));
        pushButtonValid_Edit->setText(QApplication::translate("AdminWindow", "Valid", 0));
        labelOldPassword_Edit->setText(QApplication::translate("AdminWindow", "Old Password", 0));
        labelNewLogin_Edit->setText(QApplication::translate("AdminWindow", "New Login", 0));
        labelNewPassword_Edit->setText(QApplication::translate("AdminWindow", "NewPassword", 0));
        labelConfirm_Edit->setText(QApplication::translate("AdminWindow", "Confirm Password", 0));
        pushButtonValid_Delete->setText(QApplication::translate("AdminWindow", "Valid", 0));
        labelPassword_Delete->setText(QApplication::translate("AdminWindow", "Password", 0));
        label->setText(QApplication::translate("AdminWindow", "Op\303\251ration \303\251ff\303\251ctu\303\251e", 0));
        pushButtonGetAll->setText(QApplication::translate("AdminWindow", "Get All", 0));
        pushButtonSearch->setText(QApplication::translate("AdminWindow", "Search", 0));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
