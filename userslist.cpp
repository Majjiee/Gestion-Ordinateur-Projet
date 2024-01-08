#include "userslist.h"
#include "ui_userslist.h"
#include "mainwindow.h"
#include <QCoreApplication>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QDialog>
usersList::usersList(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::usersList)
{
    ui->setupUi(this);
}

usersList::~usersList()
{
    delete ui;
}

void usersList::on_pushButton_clicked()
{
   MainWindow con;
    QSqlQueryModel * m= new QSqlQueryModel();
   con.cnOpen();
    QSqlQuery qry(con.mydb);
   qry.prepare("SELECT * FROM Users");
    qry.exec();
   m->setQuery(qry);
    ui->tableView->setModel(m);
   con.cnClose();
    qDebug()<<(m);
}

