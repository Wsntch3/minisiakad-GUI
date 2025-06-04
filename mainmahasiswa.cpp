#include "mainmahasiswa.h"
#include "ui_mainmahasiswa.h"
#include "QTextStream"
#include "QMessageBox"
#include <QString>

Mainmahasiswa::Mainmahasiswa(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mainmahasiswa)
{
    ui->setupUi(this);
    connect(ui->btnTambahMatkul, &QPushButton::clicked, this, &Mainmahasiswa::tambahmatkul);
    connect(ui->btnUndoMatkul, &QPushButton::clicked, this, &Mainmahasiswa::undomatkul);
    connect(ui->btnTampilMatkul_2, &QPushButton::clicked, this, &Mainmahasiswa::tampilkanmatkul);
    connect(ui->btnTotalSks_2, &QPushButton::clicked, this, &Mainmahasiswa::hitungsks);
    connect(ui->btnKembali,&QPushButton::clicked,this,&Mainmahasiswa::gobacktomain);

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->btnPageTambahMatkul, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
        tampilkandaftar();
    });
    connect(ui->btnTampilMatkul, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->btnPageUndoMatkul, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->btnTotalSks, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(3);
    });
}

Mainmahasiswa::~Mainmahasiswa()
{
    delete ui;
}


int hitungTotalSKS(Matkul* matkul) {
    if(matkul == nullptr) {
        return 0;
    }
    return matkul->sks + hitungTotalSKS(matkul->next);
}



void Mainmahasiswa::tampilkandaftar(){
    QString daftarText = "Daftar Mata Kuliah:\n";
    daftarText += "==================\n";
    for (int i = 0;i < 6; i++){
        daftarText += QString("ID: %1 - %2 (%3 SKS)\n")
            .arg(i + 1)
            .arg(QString::fromStdString(daftarMatkul[i].nama))
            .arg(daftarMatkul[i].sks);

    }

    daftarText += "===================\n";
    ui->outputdaftarmatkul->setPlainText(daftarText);
    ui->outputdaftarmatkul->setReadOnly(true);
}

void Mainmahasiswa::tambahkequeue(QString nim, int idMatkul){
    if(idMatkul < 1 || idMatkul > 6){
        QMessageBox::information(this, "INFO" , "ID tidak valid");
        return;
    }
    Matkul matkul;
    matkul.id = idMatkul;
    matkul.nama = daftarMatkul[idMatkul - 1].nama;
    matkul.sks = sksMatkul[idMatkul-1];
    QueueNode* newNode = new QueueNode;
    newNode->nim = nim;
    newNode->matkul = matkul;
    newNode->next = nullptr;
    if (queueRear == nullptr){
        queueFront = queueRear = newNode;
    } else {
        queueRear->next = newNode;
        queueRear = newNode;
    }
    QMessageBox::information(this,"INFO","Mata kuliah berhasil ditambahkan ke antrian");
}

void Mainmahasiswa::tambahmatkul(){
    QString nim = ui->writenim->text().trimmed();
    if(nim.isEmpty()){
        QMessageBox::information(this, "ERROR", "NIM tidak boleh kosong!");
        return;
    }

    QString idMatkulStr = ui->addmatkul->text().trimmed();
    if(idMatkulStr.isEmpty()){
        QMessageBox::information(this, "ERROR", "ID Matkul tidak boleh kosong!");
        return;
    }

    bool ok;
    int idMatkul = idMatkulStr.toInt(&ok);
    if(!ok){
        QMessageBox::information(this, "ERROR", "ID Matkul harus berupa angka!");
        return;
    }

    if(idMatkul < 1 || idMatkul > 6){
        QMessageBox::information(this,"ERROR","ID Matkul harus antara 1-6!");
        return;
    }

    Mahasiswa* current = headMahasiswa;
    while(current != nullptr && current->nim != nim){
        current = current->next;
    }

    if (current == nullptr){
        QMessageBox::information(this, "ERROR" , "Mahasiswa dengan NIM " + nim + " tidak ditemukan!");
        return;
    }

    Matkul* tempCheck = current->matkulList;
    while(tempCheck != nullptr){
        if(tempCheck->id == idMatkul){
            QMessageBox::information(this, "ERROR", "Mata kuliah sudah diambil!");
            return;
        }
        tempCheck = tempCheck->next;
    }

    Matkul* newMatkul = buatMatkul(idMatkul, daftarMatkul[idMatkul - 1].nama, sksMatkul[idMatkul - 1]);
    if (current->matkulList == nullptr){
        current->matkulList = newMatkul;
    }else {
        Matkul* temp = current->matkulList;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newMatkul;
    }

    StackNode* stacknode = new StackNode;
    stacknode->data = *newMatkul;
    stacknode->next = undoStack;
    undoStack = stacknode;

    ui->addmatkul->clear();
    ui->writenim->clear();
    tambahkequeue(nim,idMatkul);
    QMessageBox::information(this, "INFO", "Mata kuliah berhasil ditambahkan!");
}
void Mainmahasiswa::undomatkul(){
    QString nim = ui->undoperson->text().trimmed();
    if(nim.isEmpty()){
        QMessageBox::information(this, "ERROR", "NIM tidak boleh kosong!");
        return;
    }

    if(undoStack == nullptr){
        QMessageBox::information(this, "INFO", "Tidak ada mata kuliah yang bisa di-undo!");
        return;
    }

    Mahasiswa* current = headMahasiswa;
    while(current != nullptr && current->nim != nim){
        current = current->next;
    }

    if (current == nullptr){
        QMessageBox::information(this, "ERROR" , "Mahasiswa dengan NIM " + nim + " tidak ditemukan!");
        return;
    }

    if(current->matkulList != nullptr){
        if(current->matkulList->next == nullptr){
            delete current->matkulList;
            current->matkulList = nullptr;
        }else{
            Matkul* temp = current->matkulList;
            while(temp->next->next != nullptr){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        StackNode* temp = undoStack;
        undoStack = undoStack->next;
        delete temp;
        ui->undoperson->clear();
        QMessageBox::information(this,"INFO","Mata kuliah terakhir berhasil di-undo!");
    } else {
        QMessageBox::information(this,"INFO","Tidak ada mata kuliah yang bisa di-undo!");
    }
}


void Mainmahasiswa::tampilkanmatkul(){
    QString nim = ui->showmatkul->text().trimmed();
    if(nim.isEmpty()){
        QMessageBox::information(this, "ERROR", "NIM tidak boleh kosong!");
        return;
    }

    QString output;
    Mahasiswa* current = headMahasiswa;
    while(current != nullptr && current->nim != nim){
        current = current->next;
    }

    if(current == nullptr){
        QMessageBox::information(this, "ERROR" , "Mahasiswa dengan NIM " + nim + " tidak ditemukan!");
        return;
    }

    Matkul* temp = current->matkulList;
    if(temp == nullptr){
        output = "Tidak ada mata kuliah yang diambil oleh mahasiswa dengan NIM: " + nim;
    } else {
        output = "Daftar Mata Kuliah untuk NIM: " + nim + "\n\n";
        while(temp != nullptr){
            output += QString("ID: %1\nNama: %2\nSKS: %3\n\n")
            .arg(temp->id)
                .arg(QString::fromStdString(temp->nama))
                .arg(temp->sks);
            temp = temp->next;
        }
    }
    ui->outputtampilmatkul->setPlainText(output);
}
void Mainmahasiswa::hitungsks(){
    QString nim = ui->NIM->text().trimmed();
    if(nim.isEmpty()){
        QMessageBox::information(this, "ERROR", "NIM tidak boleh kosong!");
        return;
    }

    Mahasiswa* current = headMahasiswa;
    while(current != nullptr && current->nim != nim){
        current = current->next;
    }

    if(current == nullptr){
        QMessageBox::information(this, "ERROR", "Mahasiswa dengan NIM " + nim + " tidak ditemukan!");
        return;
    }
    if(current->matkulList == nullptr){
        QMessageBox::information(this, "INFO", "Mahasiswa belum mengambil mata kuliah apapun!");
        return;
    }

    int totalSKS = hitungTotalSKS(current->matkulList);
    QString message = QString("Total SKS yang diambil oleh NIM %1: %2 SKS").arg(nim).arg(totalSKS);
    ui->NIM->clear();

    QMessageBox::information(this, "Total SKS", message);
}

void Mainmahasiswa::on_btnPageTambahMatkul_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
    tampilkandaftar();
}
void Mainmahasiswa::gobacktomain(){
    this->close();
    QWidget *parentWindow = this->parentWidget();
    if(parentWindow)
        parentWindow->show();
}
void Mainmahasiswa::on_btnKembali_clicked(){
    this->close();
    QWidget *parentWindow = this->parentWidget();
    if(parentWindow)
        parentWindow->show();
}
