#ifndef COMPUTERS_H
#define COMPUTERS_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDialog>
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class computers;
}

class computers : public QDialog
{
    Q_OBJECT

public:
    explicit computers(QWidget *parent = nullptr);
    ~computers();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::computers *ui;
};

#endif // COMPUTERS_H
