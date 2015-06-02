#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AbrirDialog();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AbrirDialog()
{
    Dialog dialog;
    hd = new Disco(dialog.getQuantSetor(), dialog.getTamSetor(), dialog.getTamDisco());
    dialog.exec();
    Plotar();
}

void MainWindow::Plotar()
{
    QString grafico;
    for(int i = 0; i < hd->getNumSetores(); i++){
        grafico.push_back("[");
        for(int j = 0; j < hd->getTamSetores(); j++){
            grafico.push_back("0");
        }
        grafico.push_back("]");
    }
    ui->grafico->setText(grafico);
}

void MainWindow::on_salvar_clicked()
{
   nome = ui->CampoNome->text();
   valor = ui->CampoValor->text();

   char *strValor = new char[valor.size()];
   copy(valor.toStdString().begin(), valor.toStdString().end(), strValor);

   char *strNome = new char[nome.size()];
   copy(nome.toStdString().begin(), nome.toStdString().end(), strNome);
}
