#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "disco.h"

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
    Disco hd;
    Dialog dialog;
    dialog.exec();
    hd.setNumSetores(dialog.getQuantSetor());
    hd.setTamSetores(dialog.getTamSetor());
    hd.setTamanho(dialog.getTamDisco());
}
