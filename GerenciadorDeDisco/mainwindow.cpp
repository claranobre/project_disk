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
}

void MainWindow::Listar()
{
    ui->lista->setText(hd->Listar());
}

void MainWindow::on_salvar_clicked()
{
   nome = ui->CampoNome->text();
   valor = ui->CampoValor->text();

   QByteArray aux;
   aux = valor.toLatin1();
   const char *strValor = aux.data();

   if(hd->Salvar(strValor, valor.size(), nome.toStdString(), nome.size())){
        Plotar();
   }
}

void MainWindow::on_excluir_clicked()
{
   nome = ui->CampoNome->text();

   if(hd->Excluir(nome.toStdString())){
       Plotar();
   }
}

void MainWindow::on_listar_clicked()
{
    Listar();
}

void MainWindow::on_formatar_clicked()
{
    if(hd->Formatar()){
        Plotar();
    }
}

void MainWindow::on_buscar_clicked()
{

}
