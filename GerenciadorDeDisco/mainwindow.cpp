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
    dialog.exec();
    hd = new Disco(dialog.getQuantSetor(), dialog.getTamSetor(), dialog.getTamDisco());
    Plotar();
}

void MainWindow::Plotar()
{
    QString grafico;
    int cont = 0;
    for(int i = 0; i < hd->getNumSetores(); i++){
        grafico.push_back("[");
        for(int j = 0; j < hd->getTamSetores(); j++){
            grafico.push_back(hd->disk[cont]);
            cont++;
        }
        grafico.push_back("]");
    }
    ui->grafico->setText(grafico);
    ui->grafico->setHtml("<h1>Teste</h1>");
}

void MainWindow::on_salvar_clicked()
{
   nome = ui->CampoNome->text();
   valor = ui->CampoValor->text();

   const char *strNome = nome.toStdString().c_str();
   const char *strValor = valor.toStdString().c_str();
   if(hd->Salvar(strValor, valor.size(), strNome, nome.size())){
        Plotar();
   }

/*
   char *strNome = new char[nome.size()];
   copy(nome.toStdString().begin(), nome.toStdString().end(), strNome);
   */
}
