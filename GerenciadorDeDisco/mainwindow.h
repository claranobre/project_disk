#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void AbrirDialog(); // Abre a primeira janela para conf o disco
    void Plotar(); //Plotar gráfico
    void Listar(); //Lista os arquivos

private slots:
    void on_salvar_clicked();
    void on_excluir_clicked();
    void on_listar_clicked();

    void on_formatar_clicked();

private:
    Ui::MainWindow *ui;
    Disco *hd;
    QString nome;
    QString valor;
};

#endif // MAINWINDOW_H
