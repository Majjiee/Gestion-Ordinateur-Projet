#ifndef AFFECTLIST_H
#define AFFECTLIST_H

#include <QDialog>

namespace Ui {
class Affectlist;
}

class Affectlist : public QDialog
{
    Q_OBJECT

public:
    explicit Affectlist(QWidget *parent = nullptr);
    ~Affectlist();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Affectlist *ui;
};

#endif // AFFECTLIST_H
