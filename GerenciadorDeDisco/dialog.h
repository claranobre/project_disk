#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
    class Dialog;
}

/**
 * \class Dialog
 * \brief Classe da primeira tela do sistema. Pega os valores do usuário para realmente iniciar o sistema
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    /**
     * Retorna a quantidade de setores
     * @return retorna a quantidade de setores
     */
    int getQuantSetor() const;

    /**
     * Retorna o tamanho do disco
     * @return retorna o tamanho do disco
     */
    int getTamDisco() const;

    /**
     * Retorna o tamanho do setor
     * @return retorna o tamanho do setor
     */
    int getTamSetor() const;

private slots:
    /**
     * Altera a interface quando o usuario muda tamanho do setor
     * @param arg1 valor alterado pelo usuario
     */
    void on_valTamSetor_valueChanged(int arg1);

    /**
     * Altera a interface quando o usuario muda a quantidade de setores
     * @param arg1 valor alterado pelo usuario
     */
    void on_valQuantSetor_valueChanged(int arg1);

private:

    Ui::Dialog *ui; /**< Variável que cuida da interação com a interface */
    int tamSetor = 3; /**< Guarda o tamanho do setor */
    int quantSetor = 5; /**< Guarda a quantidade de setores */
    int tamDisco = 15; /**< Guarda o tamanho do disco */
    QString tamDiscoStr; /**< Guarda o valor do tamanho do disco em QString  */
};

#endif // DIALOG_H
