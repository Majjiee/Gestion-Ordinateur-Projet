#include "computers.h"
#include "ui_computers.h"
#include "mainwindow.h"
#include "computerslist.h"
#include <QCoreApplication>
#include <QMessageBox>
#include <QApplication>
#include <QDialog>
computers::computers(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::computers)
{
    ui->setupUi(this);
}

computers::~computers()
{
    delete ui;
}




void computers::on_pushButton_clicked()
{
    MainWindow con;
    QString nS,m,e,p,ram,tStor,cStor,nbrUsb,cont1,cont2,cont3;
    nS=ui->lineEdit->text();
    m=ui->lineEdit_2->text();
    e=ui->lineEdit_4->text();
    p=ui->lineEdit_5->text();
    ram=ui->lineEdit_6->text();
    tStor=ui->lineEdit_7->text();
    cStor=ui->lineEdit_8->text();
    nbrUsb=ui->lineEdit_9->text();
    cont1=ui->lineEdit_10->text();
    cont2=ui->lineEdit_11->text();
    cont3=ui->lineEdit_12->text();
    if(!con.cnOpen()){
        qDebug() <<"Failed to open db";
        return;
    }else{
        qDebug() <<"open db1111";
    }
    qDebug() << "Available database drivers: " << QSqlDatabase::drivers();
    con.cnOpen();
    QSqlQuery qry;
    qry.prepare("INSERT INTO Computers (NumSerie, Modele, Etat, Processeur, RAM, TypeStor, CapaciteStor, NbrPortUSB, Connectivite1, Connectivite2, Connectivite3) VALUES (:nS,:m,:e, :p,:ram, :tStor, :cStor, :nbrUsb, :cont1, :cont2, :cont3)");
    qry.bindValue(":nS", nS);
    qry.bindValue(":m", m);
    qry.bindValue(":e", e);
    qry.bindValue(":p", p);
    qry.bindValue(":ram", ram);
    qry.bindValue(":tStor", tStor);
    qry.bindValue(":cStor", cStor);
    qry.bindValue(":nbrUsb", nbrUsb);
    qry.bindValue(":cont1", cont1);
    qry.bindValue(":cont2", cont2);
    qry.bindValue(":cont3", cont3);
    qDebug() <<"cooool";
    if(qry.exec()){
        QMessageBox::information(this, "Information", "Computer Added!");
        qDebug() <<"cooool1";
    }else{

        QMessageBox::information(this, "Information", "Failed to add Computer!");
        qDebug() <<"cooool2";
    }
    con.cnClose();
}


void computers::on_pushButton_2_clicked()
{
    computerslist cl;
    cl.setModal(true);
    cl.exec();
}

