#include "computerslist.h"
#include "ui_computerslist.h"
#include "mainwindow.h"
#include <QCoreApplication>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QDialog>
computerslist::computerslist(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::computerslist)
{
    ui->setupUi(this);
}

computerslist::~computerslist()
{
    delete ui;
}

void computerslist::on_pushButton_clicked()
{
    MainWindow con;
    QSqlQueryModel * m= new QSqlQueryModel();
    con.cnOpen();
    QSqlQuery qry(con.mydb);
    qry.prepare("SELECT * FROM Computers");
    qry.exec();
    m->setQuery(qry);
    ui->tableView->setModel(m);
    con.cnClose();
    qDebug()<<(m);
}

