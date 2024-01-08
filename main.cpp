#include "mainwindow.h"
#include "users.h"
#include "userslist.h"
#include "computerslist.h"
#include "computers.h"
#include "affect.h"
#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
