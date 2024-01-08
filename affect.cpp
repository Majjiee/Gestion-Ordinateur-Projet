#include "affect.h"
#include "ui_affect.h"
#include "affectlist.h"
#include "mainwindow.h"
#include <QCoreApplication>
#include <QMessageBox>
#include <QApplication>
#include <QDialog>
Affect::Affect(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Affect)
{
    ui->setupUi(this);
}

Affect::~Affect()
{
    delete ui;
}

void Affect::on_pushButton_clicked()
{
    MainWindow con;
    int u,c;
    u = ui->lineEdit->text().toInt();
    c = ui->lineEdit_2->text().toInt();
    if(!con.cnOpen()){
        qDebug() <<"Failed to open db";
        return;
    }else{
        qDebug() <<"open db1111";
    }
    qDebug() << "Available database drivers: " << QSqlDatabase::drivers();
    con.cnOpen();
    QSqlQuery qry;
    qry.prepare("INSERT INTO Affect (U_id, C_id) VALUES (:u, :c)");
    qry.bindValue(":u", u);
    qry.bindValue(":c", c);
    qDebug() <<"cooool";
    if(qry.exec()){
        QMessageBox::information(this, "Information", "Affect success!");
        qDebug() <<"cooool1";
    }else{

        QMessageBox::information(this, "Information", "Failed to Affect!");
        qDebug() <<"cooool2";
        qDebug() << "cooool2" << qry.lastError().text();
    }
    con.cnClose();
}


void Affect::on_pushButton_2_clicked()
{
    Affectlist l;
    l.setModal(true);
    l.exec();
}

