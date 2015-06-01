#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"


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
    hd.setNumSetores(dialog.getQuantSetor());
    hd.setTamSetores(dialog.getTamSetor());
    hd.setTamanho(dialog.getTamDisco());
    Plotar();
}

void MainWindow::Plotar()
{
    QString grafico;
    for(int i = 0; i < hd.getNumSetores(); i++){
        grafico.push_back("[");
        for(int j = 0; j < hd.getTamSetores(); j++){
            grafico.push_back("0");
        }
        grafico.push_back("]");
    }
    ui->grafico->setText(grafico);
}
