/********************************************************************************
** Form generated from reading UI file 'connexionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNEXIONWINDOW_H
#define UI_CONNEXIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectionWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEditLogin;
    QLineEdit *lineEditPassword;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButtonConnection;
    QMenuBar *menubar;

    void setupUi(QMainWindow *ConnectionWindow)
    {
        if (ConnectionWindow->objectName().isEmpty())
            ConnectionWindow->setObjectName(QStringLiteral("ConnectionWindow"));
        ConnectionWindow->resize(377, 181);
        ConnectionWindow->setStyleSheet(QLatin1String("#mainFrame {\n"
"border: 3px solid gray;\n"
"border-radius: 40px;\n"
"background: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #eef, stop: 1 #ccf);\n"
"}\n"
"QLineEdit {\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}\n"
"QPushButton {\n"
"color: white;\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);\n"
"border-width: 1px;\n"
"border-color: #339;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"font-size: 10px;\n"
"}"));
        centralwidget = new QWidget(ConnectionWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        lineEditLogin = new QLineEdit(centralwidget);
        lineEditLogin->setObjectName(QStringLiteral("lineEditLogin"));
        lineEditLogin->setGeometry(QRect(80, 30, 221, 20));
        lineEditLogin->setInputMethodHints(Qt::ImhNone);
        lineEditPassword = new QLineEdit(centralwidget);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(80, 90, 221, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 70, 61, 16));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 10, 46, 16));
        pushButtonConnection = new QPushButton(centralwidget);
        pushButtonConnection->setObjectName(QStringLiteral("pushButtonConnection"));
        pushButtonConnection->setGeometry(QRect(140, 120, 91, 20));
        pushButtonConnection->setStyleSheet(QStringLiteral(""));
        ConnectionWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ConnectionWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 377, 20));
        ConnectionWindow->setMenuBar(menubar);

        retranslateUi(ConnectionWindow);

        QMetaObject::connectSlotsByName(ConnectionWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ConnectionWindow)
    {
        ConnectionWindow->setWindowTitle(QApplication::translate("ConnectionWindow", "MainWindow", 0));
        lineEditLogin->setText(QApplication::translate("ConnectionWindow", "admin", 0));
        lineEditPassword->setText(QApplication::translate("ConnectionWindow", "admin", 0));
        label_2->setText(QApplication::translate("ConnectionWindow", "Password", 0));
        label->setText(QApplication::translate("ConnectionWindow", "Login", 0));
        pushButtonConnection->setText(QApplication::translate("ConnectionWindow", "Se connecter", 0));
    } // retranslateUi

};

namespace Ui {
    class ConnectionWindow: public Ui_ConnectionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNEXIONWINDOW_H
