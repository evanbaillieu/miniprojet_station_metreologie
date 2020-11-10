#include "client/connexionwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConnectionWindow connection;
    connection.show();
    return a.exec();
}
