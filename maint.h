#ifndef MAINT_H
#define MAINT_H

#include <QDialog>

namespace Ui {
class Maint;
}

class Maint : public QDialog
{
    Q_OBJECT

public:
    explicit Maint(QWidget *parent = nullptr);
    ~Maint();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Maint *ui;
};

#endif // MAINT_H
