/********************************************************************************
** Form generated from reading UI file 'mainmahasiswa.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMAHASISWA_H
#define UI_MAINMAHASISWA_H

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

class Ui_Mainmahasiswa
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *pageTambah;
    QPlainTextEdit *outputdaftarmatkul;
    QLineEdit *addmatkul;
    QPushButton *btnTambahMatkul;
    QLineEdit *writenim;
    QLabel *label;
    QLabel *label_2;
    QWidget *pageTampil;
    QPlainTextEdit *outputtampilmatkul;
    QPushButton *btnTampilMatkul_2;
    QLineEdit *showmatkul;
    QLabel *label_3;
    QWidget *pageUndo;
    QPushButton *btnUndoMatkul;
    QLabel *keteranganundo;
    QLineEdit *undoperson;
    QWidget *page;
    QPushButton *btnTotalSks_2;
    QLabel *outputtotal;
    QLineEdit *NIM;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnPageTambahMatkul;
    QPushButton *btnPageUndoMatkul;
    QPushButton *btnTampilMatkul;
    QPushButton *btnTotalSks;
    QPushButton *btnKembali;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Mainmahasiswa)
    {
        if (Mainmahasiswa->objectName().isEmpty())
            Mainmahasiswa->setObjectName("Mainmahasiswa");
        Mainmahasiswa->resize(800, 600);
        centralwidget = new QWidget(Mainmahasiswa);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(420, 50, 281, 431));
        pageTambah = new QWidget();
        pageTambah->setObjectName("pageTambah");
        outputdaftarmatkul = new QPlainTextEdit(pageTambah);
        outputdaftarmatkul->setObjectName("outputdaftarmatkul");
        outputdaftarmatkul->setGeometry(QRect(60, 40, 171, 151));
        addmatkul = new QLineEdit(pageTambah);
        addmatkul->setObjectName("addmatkul");
        addmatkul->setGeometry(QRect(80, 300, 113, 31));
        btnTambahMatkul = new QPushButton(pageTambah);
        btnTambahMatkul->setObjectName("btnTambahMatkul");
        btnTambahMatkul->setGeometry(QRect(80, 360, 111, 29));
        writenim = new QLineEdit(pageTambah);
        writenim->setObjectName("writenim");
        writenim->setGeometry(QRect(80, 230, 113, 26));
        label = new QLabel(pageTambah);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 260, 63, 20));
        label_2 = new QLabel(pageTambah);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 330, 63, 20));
        stackedWidget->addWidget(pageTambah);
        pageTampil = new QWidget();
        pageTampil->setObjectName("pageTampil");
        outputtampilmatkul = new QPlainTextEdit(pageTampil);
        outputtampilmatkul->setObjectName("outputtampilmatkul");
        outputtampilmatkul->setGeometry(QRect(40, 90, 191, 221));
        btnTampilMatkul_2 = new QPushButton(pageTampil);
        btnTampilMatkul_2->setObjectName("btnTampilMatkul_2");
        btnTampilMatkul_2->setGeometry(QRect(80, 360, 111, 29));
        showmatkul = new QLineEdit(pageTampil);
        showmatkul->setObjectName("showmatkul");
        showmatkul->setGeometry(QRect(80, 30, 113, 26));
        label_3 = new QLabel(pageTampil);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 60, 63, 20));
        stackedWidget->addWidget(pageTampil);
        pageUndo = new QWidget();
        pageUndo->setObjectName("pageUndo");
        btnUndoMatkul = new QPushButton(pageUndo);
        btnUndoMatkul->setObjectName("btnUndoMatkul");
        btnUndoMatkul->setGeometry(QRect(30, 140, 111, 29));
        keteranganundo = new QLabel(pageUndo);
        keteranganundo->setObjectName("keteranganundo");
        keteranganundo->setGeometry(QRect(50, 90, 63, 20));
        undoperson = new QLineEdit(pageUndo);
        undoperson->setObjectName("undoperson");
        undoperson->setGeometry(QRect(40, 40, 113, 26));
        stackedWidget->addWidget(pageUndo);
        page = new QWidget();
        page->setObjectName("page");
        btnTotalSks_2 = new QPushButton(page);
        btnTotalSks_2->setObjectName("btnTotalSks_2");
        btnTotalSks_2->setGeometry(QRect(30, 180, 93, 29));
        outputtotal = new QLabel(page);
        outputtotal->setObjectName("outputtotal");
        outputtotal->setGeometry(QRect(50, 100, 63, 20));
        NIM = new QLineEdit(page);
        NIM->setObjectName("NIM");
        NIM->setGeometry(QRect(30, 40, 113, 26));
        stackedWidget->addWidget(page);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(80, 59, 181, 431));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnPageTambahMatkul = new QPushButton(verticalLayoutWidget);
        btnPageTambahMatkul->setObjectName("btnPageTambahMatkul");

        verticalLayout->addWidget(btnPageTambahMatkul);

        btnPageUndoMatkul = new QPushButton(verticalLayoutWidget);
        btnPageUndoMatkul->setObjectName("btnPageUndoMatkul");

        verticalLayout->addWidget(btnPageUndoMatkul);

        btnTampilMatkul = new QPushButton(verticalLayoutWidget);
        btnTampilMatkul->setObjectName("btnTampilMatkul");

        verticalLayout->addWidget(btnTampilMatkul);

        btnTotalSks = new QPushButton(verticalLayoutWidget);
        btnTotalSks->setObjectName("btnTotalSks");

        verticalLayout->addWidget(btnTotalSks);

        btnKembali = new QPushButton(verticalLayoutWidget);
        btnKembali->setObjectName("btnKembali");

        verticalLayout->addWidget(btnKembali);

        Mainmahasiswa->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Mainmahasiswa);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Mainmahasiswa->setMenuBar(menubar);
        statusbar = new QStatusBar(Mainmahasiswa);
        statusbar->setObjectName("statusbar");
        Mainmahasiswa->setStatusBar(statusbar);

        retranslateUi(Mainmahasiswa);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Mainmahasiswa);
    } // setupUi

    void retranslateUi(QMainWindow *Mainmahasiswa)
    {
        Mainmahasiswa->setWindowTitle(QCoreApplication::translate("Mainmahasiswa", "MainWindow", nullptr));
        btnTambahMatkul->setText(QCoreApplication::translate("Mainmahasiswa", "tambah matkul", nullptr));
        label->setText(QCoreApplication::translate("Mainmahasiswa", "NIM", nullptr));
        label_2->setText(QCoreApplication::translate("Mainmahasiswa", "Index", nullptr));
        btnTampilMatkul_2->setText(QCoreApplication::translate("Mainmahasiswa", "Tampil matkul", nullptr));
        label_3->setText(QCoreApplication::translate("Mainmahasiswa", "NIM", nullptr));
        btnUndoMatkul->setText(QCoreApplication::translate("Mainmahasiswa", "Undo Matkul", nullptr));
        keteranganundo->setText(QCoreApplication::translate("Mainmahasiswa", "NIM", nullptr));
        btnTotalSks_2->setText(QCoreApplication::translate("Mainmahasiswa", "Total Sks", nullptr));
        outputtotal->setText(QCoreApplication::translate("Mainmahasiswa", "NIM", nullptr));
        btnPageTambahMatkul->setText(QCoreApplication::translate("Mainmahasiswa", "tambah matkul", nullptr));
        btnPageUndoMatkul->setText(QCoreApplication::translate("Mainmahasiswa", "undo matkul", nullptr));
        btnTampilMatkul->setText(QCoreApplication::translate("Mainmahasiswa", "tampilkan matkul", nullptr));
        btnTotalSks->setText(QCoreApplication::translate("Mainmahasiswa", "Total sks", nullptr));
        btnKembali->setText(QCoreApplication::translate("Mainmahasiswa", "kembali", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mainmahasiswa: public Ui_Mainmahasiswa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMAHASISWA_H
