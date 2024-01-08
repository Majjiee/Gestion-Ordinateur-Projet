#include "affectlist.h"
#include "ui_affectlist.h"
#include "mainwindow.h"
#include <QCoreApplication>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QApplication>
#include <QDialog>
Affectlist::Affectlist(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Affectlist)
{
    ui->setupUi(this);
}

Affectlist::~Affectlist()
{
    delete ui;
}

void Affectlist::on_pushButton_clicked()
{
    MainWindow con;
    QSqlQueryModel * m= new QSqlQueryModel();
    con.cnOpen();
    QSqlQuery qry(con.mydb);
    qry.prepare("SELECT * FROM Affect");
    qry.exec();
    m->setQuery(qry);
    ui->tableView->setModel(m);
    con.cnClose();
    qDebug()<<(m);
}

