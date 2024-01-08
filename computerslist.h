#ifndef COMPUTERSLIST_H
#define COMPUTERSLIST_H
#include <QDialog>
#include <QWidget>

namespace Ui {
class computerslist;
}

class computerslist : public QDialog
{
    Q_OBJECT

public:
    explicit computerslist(QWidget *parent = nullptr);
    ~computerslist();

private slots:
    void on_pushButton_clicked();

private:
    Ui::computerslist *ui;
};

#endif // COMPUTERSLIST_H
