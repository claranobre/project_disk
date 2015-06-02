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
    void AbrirDialog();
    void Plotar(); //Plotar gráfico

private slots:
    void on_salvar_clicked();

private:
    Ui::MainWindow *ui;
    Disco *hd;
    QString nome;
    QString valor;

};

#endif // MAINWINDOW_H
