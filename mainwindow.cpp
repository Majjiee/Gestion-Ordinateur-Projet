#include "mainwindow.h"
#include "computers.h"
#include "users.h"
#include "affect.h"
#include "maint.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_6_clicked()
{
    computers c;
    c.setModal(true);
    c.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    users u;
    u.setModal(true);
    u.exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    Affect v;
    v.setModal(true);
    v.exec();
}


void MainWindow::on_pushButton_5_clicked()
{
    Maint m;
    m.setModal(true);
    m.exec();
}

