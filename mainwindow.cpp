#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    mhsWindow = nullptr;
    adminWindow = nullptr;
    dosenWindow = nullptr;
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btnMahasiswa_clicked() {
    if (!mhsWindow)
        mhsWindow = new Mainmahasiswa(this);
    mhsWindow->show();
    this->hide();
}

void MainWindow::on_btnAdmin_clicked() {
    if (!adminWindow)
        adminWindow = new Mainadmin(this);
    adminWindow->show();
    this->hide();
}

void MainWindow::on_btnDosen_clicked() {
    if (!dosenWindow)
        dosenWindow = new Maindosen(this);
    dosenWindow->show();
    this->hide();
}
