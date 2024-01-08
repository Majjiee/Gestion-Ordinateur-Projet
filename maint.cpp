#include "maint.h"
#include "ui_maint.h"
#include <QCoreApplication>
#include <QMessageBox>
#include "mainwindow.h"
#include "maint.h"
#include "ui_maint.h"
Maint::Maint(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Maint)
{
    ui->setupUi(this);
}

Maint::~Maint()
{
    delete ui;
}

void Maint::on_pushButton_clicked()
{
    MainWindow con;
    QString d;
    QDate dd, df;
    bool c, cc;
    int i;

    i = ui->lineEdit->text().toInt();
    dd = ui->dateEdit->date();
    df = ui->dateEdit_2->date();
    c = ui->checkBox->isChecked();
    cc = ui->checkBox_2->isChecked();
    d = ui->lineEdit_2->text();

    if (!con.cnOpen()) {
        qDebug() << "Failed to open db";
        return;
    } else {
        qDebug() << "Open db1111";
    }

    qDebug() << "Available database drivers: " << QSqlDatabase::drivers();
    con.cnOpen();
    QSqlQuery qry;

    qry.prepare("INSERT INTO Maint (c_id, type1, type2, DtD, dtF, descrp) VALUES (:i, :c, :cc, :dd, :df, :d)");
    qry.bindValue(":i", i);
    qry.bindValue(":dd", dd.toString("yyyy-MM-dd"));
    qry.bindValue(":df", df.toString("yyyy-MM-dd"));
    qry.bindValue(":d", d);
    qry.bindValue(":c", c);
    qry.bindValue(":cc", cc);

    if(qry.exec()){
        QMessageBox::information(this, "Information", "Maint Added!");
        qDebug() << "cooool1";
    } else {
        QMessageBox::information(this, "Information", "Failed to maint! Error: " + qry.lastError().text());
        qDebug() << "cooool2" << qry.lastError().text();
    }

    con.cnClose();
}

