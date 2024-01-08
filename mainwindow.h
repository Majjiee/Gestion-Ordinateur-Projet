#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QSqlDatabase mydb;
    void cnClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool cnOpen(){
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");

        mydb.setDatabaseName("C:\\Users\\Hp\\OneDrive\\Documents\\GestionOrdinateurDb.db");
        if(!mydb.open()){
            qDebug()<<("Failed to open db");
            return false;
        }else{
            qDebug()<<("succeded to open db");
            return true;
        }
    }
    ~MainWindow();

private slots:


    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
