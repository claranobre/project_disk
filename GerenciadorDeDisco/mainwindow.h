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
    void AbrirDialog();/**< Abre a primeira tela do sistema */ // Abre a primeira janela para conf o disco
    void Plotar(); //Plotar gráfico
    void Listar(); //Lista os arquivos

private slots:
    /**
     * Função chamada ao clicar no botão Salvar
     */
    void on_salvar_clicked();

    /**
     * Função chamada ao clicar no botão Excluir
     */
    void on_excluir_clicked();

    /**
     * Função chamada ao clicar no botão Listar
     */
    void on_listar_clicked();

    /**
     * Função chamada ao clicar no botão Formatar
     */
    void on_formatar_clicked();

    /**
     * Função chamada ao clicar no botão Buscar
     */
    void on_buscar_clicked();

    /**
     * Função chamada ao clicar no botão Desfragmentar
     */
    void on_desfragmentar_clicked();

private:
    Ui::MainWindow *ui;
    Disco *hd;
    QString nome;
    QString valor;
};

#endif // MAINWINDOW_H
