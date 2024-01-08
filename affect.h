#ifndef AFFECT_H
#define AFFECT_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDebug>
#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Affect;
}

class Affect : public QDialog
{
    Q_OBJECT

public:
    explicit Affect(QWidget *parent = nullptr);
    ~Affect();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Affect *ui;
};

#endif // AFFECT_H
