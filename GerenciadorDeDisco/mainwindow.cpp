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
    delete hd;
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
    grafico.push_back("<style type='text/css'>");
    grafico.push_back(".celula{border-collapse:collapse;border-color:#3366FF;}.celula th{font-family:Arial, sans-serif;font-weight:normal;padding:10px 10px;border-style:solid;border-width:1px;border-color:#3366FF;background-color:#f0f0f0;}");
    grafico.push_back("</style>");
    grafico.push_back("<table class='celula'>");

    int cont = 0;
    for(int i = 0; i < hd->getNumSetores(); i++){
        grafico.push_back("<tr>");
        for(int j = 0; j < hd->getTamSetores(); j++){
            grafico.push_back("<th>");
            grafico.push_back(hd->getDisk(cont));
            grafico.push_back("</th>");
            cont++;
        }
        grafico.push_back("</tr>");
    }

    grafico.push_back("</table>");
    ui->grafico->setText(grafico);
}

void MainWindow::on_salvar_clicked()
{
   nome = ui->CampoNome->text();
   valor = ui->CampoValor->text();

   QByteArray aux;
   aux = valor.toLatin1();
   const char *strValor = aux.data();

   if(hd->Salvar(strValor, valor.size(), nome.toStdString())){
        Plotar();
   }
}

void MainWindow::on_excluir_clicked()
{
   nome = ui->CampoNome->text();

   if(hd->Excluir(nome.toStdString())){
       Plotar();
   }else{
       // não tem o arquivo. Mandar uma msg
   }
}

void MainWindow::on_listar_clicked()
{
    ui->lista->setText(hd->Listar());
}

void MainWindow::on_formatar_clicked()
{
    if(hd->Formatar()){
        Plotar();
    }
}

void MainWindow::on_buscar_clicked()
{
    nome = ui->CampoNome->text();
    ui->lista->setText(hd->Buscar(nome.toStdString()));
}

void MainWindow::on_desfragmentar_clicked()
{
    if(hd->Desfragmentar()){
        Plotar();
    }
}
