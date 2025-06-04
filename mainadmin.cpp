#include "mainadmin.h"
#include "ui_mainadmin.h"
#include <QMessageBox>
#include "common.h"

Mainadmin::Mainadmin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mainadmin)
{
    ui->setupUi(this);
    connect(ui->btnTambahMhs, &QPushButton::clicked, this, &Mainadmin::tambahMahasiswa);
    connect(ui->btnTambahKelas, &QPushButton::clicked, this, &Mainadmin::tambahkekelas);
    connect(ui->btnPageKeluar,&QPushButton::clicked,this,&Mainadmin::gobacktomain);

    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->btnPageTambahMhs, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btnPageKelas, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
}

Mainadmin::~Mainadmin()
{
    delete ui;
}

bool simpanMahasiswa(QString nim, QString nama) {
    Mahasiswa* existing = cariMahasiswa(nim);
    if (existing != nullptr) {
        return false;
    }

    Mahasiswa* newMahasiswa = new Mahasiswa;
    newMahasiswa->nim = nim;
    newMahasiswa->nama = nama;
    newMahasiswa->matkulList = nullptr;
    newMahasiswa->accMatkulList = nullptr;
    newMahasiswa->isAccepted = false;
    newMahasiswa->kelas = "";
    newMahasiswa->next = nullptr;

    if (headMahasiswa == nullptr) {
        headMahasiswa = newMahasiswa;
    } else {
        Mahasiswa* temp = headMahasiswa;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newMahasiswa;
    }

    int index = hashFunction(nim);
    HashNode* hashNode = new HashNode;
    hashNode->mahasiswa = newMahasiswa;
    hashNode->next = hashTable[index];
    hashTable[index] = hashNode;

    return true;
}


void Mainadmin::tambahMahasiswa()
{
    QString nimStr = ui->inputnimm->text().trimmed();
    QString namaStr = ui->inputnama->text().trimmed();

    if(nimStr.isEmpty() || namaStr.isEmpty()) {
        QMessageBox::warning(this, "Error", "NIM dan Nama tidak boleh kosong!");
        return;
    }
    QString nim = nimStr;
    QString nama = namaStr;

    simpanMahasiswa(nim,nama);

    QMessageBox::information(this, "Sukses", "Mahasiswa berhasil ditambahkan!");
    ui->inputnimm->clear();
    ui->inputnama->clear();
}

void Mainadmin::tambahkekelas() {
    QString nim = ui->inputmin->text().trimmed();
    QString kelas = ui->inputkelas->text().trimmed();

    Mahasiswa* mahasiswa = cariMahasiswa(nim);

    if (mahasiswa == nullptr) {
        QMessageBox::information(this, "INFO", "Mahasiswa tidak ditemukan");
        return;
    }

    if (!mahasiswa->isAccepted) {
        QMessageBox::information(this, "INFO", "Mahasiswa belum di-ACC");
    } else {
        mahasiswa->kelas = kelas.toStdString();
        QString info = "Mahasiswa " + mahasiswa->nama +
                       " berhasil ditambahkan ke kelas " + kelas;
        QMessageBox::information(this, "INFO", info);
    }
}
void Mainadmin::gobacktomain(){
    this->close();
    QWidget *parentWindow = this->parentWidget();
    if(parentWindow)
        parentWindow->show();
}
void Mainadmin::on_btnKembali_clicked(){
    this->close();
    QWidget *parentWindow = this->parentWidget();
    if (parentWindow)
        parentWindow->show();
}
