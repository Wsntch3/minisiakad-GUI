/********************************************************************************
** Form generated from reading UI file 'maindosen.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDOSEN_H
#define UI_MAINDOSEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Maindosen
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnPageAcc;
    QPushButton *btnPageCari;
    QPushButton *btnPageTampil;
    QPushButton *btnKembali;
    QStackedWidget *stackedWidget;
    QWidget *pagetambah;
    QPushButton *btnAcc;
    QPlainTextEdit *tampilqueue;
    QWidget *pageCari;
    QLineEdit *inputnim;
    QPushButton *btnCari;
    QPlainTextEdit *tampilmahasiswa;
    QLabel *label;
    QWidget *page;
    QPushButton *btnTampilMhs;
    QPlainTextEdit *tampilmhs;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Maindosen)
    {
        if (Maindosen->objectName().isEmpty())
            Maindosen->setObjectName("Maindosen");
        Maindosen->resize(800, 600);
        centralwidget = new QWidget(Maindosen);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(60, 80, 160, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnPageAcc = new QPushButton(verticalLayoutWidget);
        btnPageAcc->setObjectName("btnPageAcc");

        verticalLayout->addWidget(btnPageAcc);

        btnPageCari = new QPushButton(verticalLayoutWidget);
        btnPageCari->setObjectName("btnPageCari");

        verticalLayout->addWidget(btnPageCari);

        btnPageTampil = new QPushButton(verticalLayoutWidget);
        btnPageTampil->setObjectName("btnPageTampil");

        verticalLayout->addWidget(btnPageTampil);

        btnKembali = new QPushButton(verticalLayoutWidget);
        btnKembali->setObjectName("btnKembali");

        verticalLayout->addWidget(btnKembali);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(340, 100, 381, 341));
        pagetambah = new QWidget();
        pagetambah->setObjectName("pagetambah");
        btnAcc = new QPushButton(pagetambah);
        btnAcc->setObjectName("btnAcc");
        btnAcc->setGeometry(QRect(20, 30, 93, 29));
        tampilqueue = new QPlainTextEdit(pagetambah);
        tampilqueue->setObjectName("tampilqueue");
        tampilqueue->setGeometry(QRect(20, 90, 131, 241));
        stackedWidget->addWidget(pagetambah);
        pageCari = new QWidget();
        pageCari->setObjectName("pageCari");
        inputnim = new QLineEdit(pageCari);
        inputnim->setObjectName("inputnim");
        inputnim->setGeometry(QRect(10, 40, 113, 26));
        btnCari = new QPushButton(pageCari);
        btnCari->setObjectName("btnCari");
        btnCari->setGeometry(QRect(10, 100, 93, 29));
        tampilmahasiswa = new QPlainTextEdit(pageCari);
        tampilmahasiswa->setObjectName("tampilmahasiswa");
        tampilmahasiswa->setGeometry(QRect(10, 150, 151, 171));
        label = new QLabel(pageCari);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 70, 63, 20));
        stackedWidget->addWidget(pageCari);
        page = new QWidget();
        page->setObjectName("page");
        btnTampilMhs = new QPushButton(page);
        btnTampilMhs->setObjectName("btnTampilMhs");
        btnTampilMhs->setGeometry(QRect(140, 10, 93, 29));
        tampilmhs = new QPlainTextEdit(page);
        tampilmhs->setObjectName("tampilmhs");
        tampilmhs->setGeometry(QRect(40, 60, 301, 271));
        stackedWidget->addWidget(page);
        Maindosen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Maindosen);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Maindosen->setMenuBar(menubar);
        statusbar = new QStatusBar(Maindosen);
        statusbar->setObjectName("statusbar");
        Maindosen->setStatusBar(statusbar);

        retranslateUi(Maindosen);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Maindosen);
    } // setupUi

    void retranslateUi(QMainWindow *Maindosen)
    {
        Maindosen->setWindowTitle(QCoreApplication::translate("Maindosen", "MainWindow", nullptr));
        btnPageAcc->setText(QCoreApplication::translate("Maindosen", "AccMahasiswa", nullptr));
        btnPageCari->setText(QCoreApplication::translate("Maindosen", "Cari Mahasiswa", nullptr));
        btnPageTampil->setText(QCoreApplication::translate("Maindosen", "Tampilkan Mahasiswa", nullptr));
        btnKembali->setText(QCoreApplication::translate("Maindosen", "PushButton", nullptr));
        btnAcc->setText(QCoreApplication::translate("Maindosen", "PushButton", nullptr));
        btnCari->setText(QCoreApplication::translate("Maindosen", "Cari", nullptr));
        label->setText(QCoreApplication::translate("Maindosen", "NIM", nullptr));
        btnTampilMhs->setText(QCoreApplication::translate("Maindosen", "Tampilkan", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Maindosen: public Ui_Maindosen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDOSEN_H
