#include "users.h"
#include "mainwindow.h"
#include "ui_users.h"
#include "userslist.h"
#include <QCoreApplication>
#include <QMessageBox>
#include <QDialog>
users::users(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::users)
{
    ui->setupUi(this);
}

users::~users()
{
    delete ui;
}

void users::on_pushButton_clicked()
{
    MainWindow con;
    QString n,p,a;
    n=ui->lineEdit->text();
    p=ui->lineEdit_2->text();
    a=ui->lineEdit_3->text();
    if(!con.cnOpen()){
        qDebug() <<"Failed to open db";
        return;
    }else{
       qDebug() <<"open db1111";
    }
    qDebug() << "Available database drivers: " << QSqlDatabase::drivers();
    con.cnOpen();
    QSqlQuery qry;
    qry.prepare("INSERT INTO Users (NomUser, PrenomUser, AdressUser) VALUES (:n,:p,:a)");
    qry.bindValue(":n", n);
    qry.bindValue(":p", p);
    qry.bindValue(":a", a);
    qDebug() <<"cooool";
    if(qry.exec()){
        QMessageBox::information(this, "Information", "User Added!");
        qDebug() <<"cooool1";
    }else{

        QMessageBox::information(this, "Information", "Failed to add User!");
        qDebug() <<"cooool2";
    }
    con.cnClose();

}


void users::on_pushButton_2_clicked()
{
    usersList ul;
    ul.setModal(true);
    ul.exec();
}

