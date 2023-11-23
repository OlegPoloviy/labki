#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

// Оголошення функції f
float f(float x);

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void setValues(float N, float a, float b);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
