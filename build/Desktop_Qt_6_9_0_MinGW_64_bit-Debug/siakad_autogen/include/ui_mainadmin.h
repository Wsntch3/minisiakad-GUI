/********************************************************************************
** Form generated from reading UI file 'mainadmin.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINADMIN_H
#define UI_MAINADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mainadmin
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnPageTambahMhs;
    QPushButton *btnPageKelas;
    QPushButton *btnPageKeluar;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *inputnama;
    QLineEdit *inputnimm;
    QPushButton *btnTambahMhs;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *page_2;
    QLineEdit *inputmin;
    QPushButton *btnTambahKelas;
    QLineEdit *inputkelas;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Mainadmin)
    {
        if (Mainadmin->objectName().isEmpty())
            Mainadmin->setObjectName("Mainadmin");
        Mainadmin->resize(800, 600);
        centralwidget = new QWidget(Mainadmin);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(40, 50, 171, 431));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnPageTambahMhs = new QPushButton(verticalLayoutWidget);
        btnPageTambahMhs->setObjectName("btnPageTambahMhs");

        verticalLayout->addWidget(btnPageTambahMhs);

        btnPageKelas = new QPushButton(verticalLayoutWidget);
        btnPageKelas->setObjectName("btnPageKelas");

        verticalLayout->addWidget(btnPageKelas);

        btnPageKeluar = new QPushButton(verticalLayoutWidget);
        btnPageKeluar->setObjectName("btnPageKeluar");

        verticalLayout->addWidget(btnPageKeluar);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(360, 70, 271, 401));
        page = new QWidget();
        page->setObjectName("page");
        inputnama = new QLineEdit(page);
        inputnama->setObjectName("inputnama");
        inputnama->setGeometry(QRect(20, 50, 113, 26));
        inputnimm = new QLineEdit(page);
        inputnimm->setObjectName("inputnimm");
        inputnimm->setGeometry(QRect(20, 140, 113, 26));
        btnTambahMhs = new QPushButton(page);
        btnTambahMhs->setObjectName("btnTambahMhs");
        btnTambahMhs->setGeometry(QRect(30, 240, 93, 29));
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 90, 63, 20));
        label_4 = new QLabel(page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 190, 63, 20));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        inputmin = new QLineEdit(page_2);
        inputmin->setObjectName("inputmin");
        inputmin->setGeometry(QRect(80, 70, 113, 26));
        btnTambahKelas = new QPushButton(page_2);
        btnTambahKelas->setObjectName("btnTambahKelas");
        btnTambahKelas->setGeometry(QRect(90, 270, 93, 29));
        inputkelas = new QLineEdit(page_2);
        inputkelas->setObjectName("inputkelas");
        inputkelas->setGeometry(QRect(80, 170, 113, 26));
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 110, 63, 20));
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 220, 63, 20));
        stackedWidget->addWidget(page_2);
        Mainadmin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Mainadmin);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Mainadmin->setMenuBar(menubar);
        statusbar = new QStatusBar(Mainadmin);
        statusbar->setObjectName("statusbar");
        Mainadmin->setStatusBar(statusbar);

        retranslateUi(Mainadmin);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Mainadmin);
    } // setupUi

    void retranslateUi(QMainWindow *Mainadmin)
    {
        Mainadmin->setWindowTitle(QCoreApplication::translate("Mainadmin", "MainWindow", nullptr));
        btnPageTambahMhs->setText(QCoreApplication::translate("Mainadmin", "tambah mahasiswa", nullptr));
        btnPageKelas->setText(QCoreApplication::translate("Mainadmin", "tambah ke kelas", nullptr));
        btnPageKeluar->setText(QCoreApplication::translate("Mainadmin", "keluar", nullptr));
        btnTambahMhs->setText(QCoreApplication::translate("Mainadmin", "tambah mhs", nullptr));
        label_3->setText(QCoreApplication::translate("Mainadmin", "Nama", nullptr));
        label_4->setText(QCoreApplication::translate("Mainadmin", "NIM", nullptr));
        btnTambahKelas->setText(QCoreApplication::translate("Mainadmin", "Tambah kelas", nullptr));
        label->setText(QCoreApplication::translate("Mainadmin", "Nim", nullptr));
        label_2->setText(QCoreApplication::translate("Mainadmin", "Kelas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mainadmin: public Ui_Mainadmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINADMIN_H
