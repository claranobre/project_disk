#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStandardItem>
#include <QMainWindow>
#include "disco.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void AbrirDialog();
    void Plotar(); //Plotar gráfico
    void Listar();

private slots:
    void on_salvar_clicked();

    void on_excluir_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    Disco *hd;
    QString nome;
    QString valor;

};

#endif // MAINWINDOW_H
