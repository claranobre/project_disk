#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    int getQuantSetor() const;
    void setQuantSetor(int value);

    int getTamDisco() const;
    void setTamDisco(int value);

    int getTamSetor() const;
    void setTamSetor(int value);

private slots:
    void on_valTamSetor_valueChanged(int arg1);
    void on_valQuantSetor_valueChanged(int arg1);

private:
    Ui::Dialog *ui;

    int tamSetor;
    int quantSetor;
    int tamDisco;
    QString tamDiscoStr;
};

#endif // DIALOG_H
