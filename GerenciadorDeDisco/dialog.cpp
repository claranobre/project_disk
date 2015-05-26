#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_valTamSetor_valueChanged(int arg1)
{
    tamSetor = ui->valTamSetor->value();
    quantSetor = ui->valQuantSetor->value();
    tamDisco = tamSetor*quantSetor;
    tamDiscoStr = QString::number(tamDisco);
    ui->valTamDisco->setText(tamDiscoStr);
}

void Dialog::on_valQuantSetor_valueChanged(int arg1)
{
    tamSetor = ui->valTamSetor->value();
    quantSetor = ui->valQuantSetor->value();
    tamDisco = tamSetor*quantSetor;
    tamDiscoStr = QString::number(tamDisco);
    ui->valTamDisco->setText(tamDiscoStr);
}
int Dialog::getTamSetor() const
{
    return tamSetor;
}

void Dialog::setTamSetor(int value)
{
    tamSetor = value;
}

int Dialog::getTamDisco() const
{
    return tamDisco;
}

void Dialog::setTamDisco(int value)
{
    tamDisco = value;
}

int Dialog::getQuantSetor() const
{
    return quantSetor;
}

void Dialog::setQuantSetor(int value)
{
    quantSetor = value;
}
