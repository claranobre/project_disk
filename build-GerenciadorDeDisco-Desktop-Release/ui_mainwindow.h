/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *LabelNome;
    QLineEdit *CampoNome;
    QPushButton *excluir;
    QPushButton *desfragmentar;
    QLabel *LabelValor;
    QLineEdit *CampoValor;
    QPushButton *salvar;
    QPushButton *listar;
    QPushButton *formatar;
    QPushButton *buscar;
    QTextBrowser *grafico;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(663, 485);
        MainWindow->setWindowOpacity(1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 340, 641, 91));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        LabelNome = new QLabel(layoutWidget);
        LabelNome->setObjectName(QStringLiteral("LabelNome"));
        QFont font;
        font.setPointSize(12);
        LabelNome->setFont(font);

        gridLayout->addWidget(LabelNome, 0, 0, 1, 1);

        CampoNome = new QLineEdit(layoutWidget);
        CampoNome->setObjectName(QStringLiteral("CampoNome"));
        CampoNome->setFont(font);

        gridLayout->addWidget(CampoNome, 0, 1, 1, 1);

        excluir = new QPushButton(layoutWidget);
        excluir->setObjectName(QStringLiteral("excluir"));

        gridLayout->addWidget(excluir, 0, 2, 1, 1);

        desfragmentar = new QPushButton(layoutWidget);
        desfragmentar->setObjectName(QStringLiteral("desfragmentar"));

        gridLayout->addWidget(desfragmentar, 0, 4, 1, 1);

        LabelValor = new QLabel(layoutWidget);
        LabelValor->setObjectName(QStringLiteral("LabelValor"));
        LabelValor->setFont(font);

        gridLayout->addWidget(LabelValor, 1, 0, 1, 1);

        CampoValor = new QLineEdit(layoutWidget);
        CampoValor->setObjectName(QStringLiteral("CampoValor"));
        CampoValor->setFont(font);

        gridLayout->addWidget(CampoValor, 1, 1, 1, 1);

        salvar = new QPushButton(layoutWidget);
        salvar->setObjectName(QStringLiteral("salvar"));

        gridLayout->addWidget(salvar, 1, 2, 1, 1);

        listar = new QPushButton(layoutWidget);
        listar->setObjectName(QStringLiteral("listar"));

        gridLayout->addWidget(listar, 1, 3, 1, 1);

        formatar = new QPushButton(layoutWidget);
        formatar->setObjectName(QStringLiteral("formatar"));

        gridLayout->addWidget(formatar, 1, 4, 1, 1);

        buscar = new QPushButton(layoutWidget);
        buscar->setObjectName(QStringLiteral("buscar"));

        gridLayout->addWidget(buscar, 0, 3, 1, 1);

        grafico = new QTextBrowser(centralWidget);
        grafico->setObjectName(QStringLiteral("grafico"));
        grafico->setGeometry(QRect(5, 11, 651, 321));
        grafico->setHtml(QLatin1String("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p></body></html>"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 663, 18));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        LabelNome->setText(QApplication::translate("MainWindow", "Nome do arquivo:", 0));
        excluir->setText(QApplication::translate("MainWindow", "Excluir", 0));
        desfragmentar->setText(QApplication::translate("MainWindow", "Desfragmentar", 0));
        LabelValor->setText(QApplication::translate("MainWindow", "Valor:", 0));
        salvar->setText(QApplication::translate("MainWindow", "Salvar", 0));
        listar->setText(QApplication::translate("MainWindow", "Listar", 0));
        formatar->setText(QApplication::translate("MainWindow", "Formatar", 0));
        buscar->setText(QApplication::translate("MainWindow", "Buscar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
