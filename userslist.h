#ifndef USERSLIST_H
#define USERSLIST_H
#include <QDialog>
#include <QDialog>

namespace Ui {
class usersList;
}

class usersList : public QDialog
{
    Q_OBJECT

public:
    explicit usersList(QWidget *parent = nullptr);
    ~usersList();

private slots:
    void on_pushButton_clicked();

private:
    Ui::usersList *ui;
};

#endif // USERSLIST_H
