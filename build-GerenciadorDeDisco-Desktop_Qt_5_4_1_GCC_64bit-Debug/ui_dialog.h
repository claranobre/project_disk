/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *quantSetor;
    QSpinBox *valQuantSetor;
    QLabel *tamSetor;
    QSpinBox *valTamSetor;
    QLabel *tamDisco;
    QLabel *valTamDisco;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(355, 264);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 210, 261, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 20, 168, 24));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 60, 271, 91));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        quantSetor = new QLabel(layoutWidget);
        quantSetor->setObjectName(QStringLiteral("quantSetor"));
        QFont font1;
        font1.setPointSize(12);
        quantSetor->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, quantSetor);

        valQuantSetor = new QSpinBox(layoutWidget);
        valQuantSetor->setObjectName(QStringLiteral("valQuantSetor"));
        valQuantSetor->setFont(font1);
        valQuantSetor->setMinimum(1);
        valQuantSetor->setValue(5);

        formLayout->setWidget(0, QFormLayout::FieldRole, valQuantSetor);

        tamSetor = new QLabel(layoutWidget);
        tamSetor->setObjectName(QStringLiteral("tamSetor"));
        tamSetor->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, tamSetor);

        valTamSetor = new QSpinBox(layoutWidget);
        valTamSetor->setObjectName(QStringLiteral("valTamSetor"));
        valTamSetor->setFont(font1);
        valTamSetor->setMinimum(1);
        valTamSetor->setMaximum(15);
        valTamSetor->setValue(3);

        formLayout->setWidget(1, QFormLayout::FieldRole, valTamSetor);

        tamDisco = new QLabel(layoutWidget);
        tamDisco->setObjectName(QStringLiteral("tamDisco"));
        tamDisco->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, tamDisco);

        valTamDisco = new QLabel(layoutWidget);
        valTamDisco->setObjectName(QStringLiteral("valTamDisco"));
        valTamDisco->setFont(font1);

        formLayout->setWidget(2, QFormLayout::FieldRole, valTamDisco);

        layoutWidget->raise();
        buttonBox->raise();
        label->raise();

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        label->setText(QApplication::translate("Dialog", "Simulador de disco", 0));
        quantSetor->setText(QApplication::translate("Dialog", "Quantidade de Setores", 0));
        tamSetor->setText(QApplication::translate("Dialog", "Tamanho do Setor", 0));
        tamDisco->setText(QApplication::translate("Dialog", "Tamanho do Disco", 0));
        valTamDisco->setText(QApplication::translate("Dialog", "15", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
