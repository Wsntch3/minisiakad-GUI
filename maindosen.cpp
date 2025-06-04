#include "maindosen.h"
#include "ui_maindosen.h"
#include <QMessageBox>
#include "common.h"

Maindosen::Maindosen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Maindosen)
{
    ui->setupUi(this);
    connect(ui->btnAcc, &QPushButton::clicked, this, &Maindosen::accMatkul);
    connect(ui->btnCari, &QPushButton::clicked, this, &Maindosen::carimahasiswa);
    connect(ui->btnTampilMhs, &QPushButton::clicked, this, &Maindosen::tampilkanMahasiswa);
    connect(ui->btnKembali,&QPushButton::clicked,this,&Maindosen::gobacktomain);

    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->btnPageAcc, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btnPageCari, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->btnPageTampil, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(2);
    });
}

Maindosen::~Maindosen()
{
    delete ui;
}



void Maindosen::accMatkul() {
    if (queueFront == nullptr) {
        QMessageBox::information(this,"INFO","Tidak ada antrian untuk di acc");
        return;
    }

    QueueNode* temp = queueFront;
    QString nim = temp->nim;
    Matkul matkulACC = temp->matkul;

    queueFront = queueFront->next;
    if (queueFront == nullptr) {
        queueRear = nullptr;
    }

    Mahasiswa* current = headMahasiswa;
    while (current != nullptr && current->nim != nim) {
        current = current->next;
    }

    if (current != nullptr) {
        Matkul* newAccMatkul = buatMatkul(matkulACC.id, matkulACC.nama, matkulACC.sks);

        if (current->accMatkulList == nullptr) {
            current->accMatkulList = newAccMatkul;
        } else {
            Matkul* tempMatkul = current->accMatkulList;
            while (tempMatkul->next != nullptr) {
                tempMatkul = tempMatkul->next;
            }
            tempMatkul->next = newAccMatkul;
        }

        current->isAccepted = true;
        QString info = "Mata kuliah " + QString::fromStdString(matkulACC.nama) +
                       " untuk mahasiswa " + current->nama +
                       " berhasil di-ACC!";
        ui->tampilqueue->appendPlainText(info);
    }

    delete temp;
}

void Maindosen::carimahasiswa(){
    QString nimInput = ui->inputnim->text().trimmed();
    if (nimInput.isEmpty()) {
        ui->tampilmahasiswa->appendPlainText("NIM tidak boleh kosong.");
        return;
    }

    QString nimStd = nimInput;
    Mahasiswa* result = cariMahasiswa(nimStd);

    if (result != nullptr) {
        QString info;
        info += "Mahasiswa ditemukan!\n";
        info += "NIM: " + result->nim + "\n";
        info += "Nama: " + result->nama + "\n";
        info += "Status: " + QString(result->isAccepted ? "Sudah di-ACC" : "Belum di-ACC") + "\n";
        info += "Kelas: " + (result->kelas.empty() ? "Belum ditentukan" : QString::fromStdString(result->kelas));

        ui->tampilmahasiswa->appendPlainText(info);
    } else {
        ui->tampilmahasiswa->appendPlainText("Mahasiswa tidak ditemukan!");
    }
}

void Maindosen::tampilkanTree(TreeNode* root){
    if (root != nullptr) {
        tampilkanTree(root->left);

        ui->tampilmhs->appendPlainText("\nMahasiswa: " +
         QString::fromStdString(root->nama) + " (" + QString::fromStdString(root->nim) + ")");
        ui->tampilmhs->appendPlainText("Mata kuliah yang diambil:");

        Matkul* temp = root->matkulList;
        if (temp == nullptr) {
            ui->tampilmhs->appendPlainText("- Belum mengambil mata kuliah");
        } else {
            while (temp != nullptr) {
                QString mk = "- " + QString::fromStdString(temp->nama) +
                             " (" + QString::number(temp->sks) + " SKS)";
                ui->tampilmhs->appendPlainText(mk);
                temp = temp->next;
            }
        }

        tampilkanTree(root->right);
    }
}


void Maindosen::sortMahasiswa(){
    if (headMahasiswa == nullptr || headMahasiswa->next == nullptr) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Mahasiswa* current = headMahasiswa;

        while (current->next != nullptr) {
            if (current->nim > current->next->nim) {
                std::swap(current->nim, current->next->nim);
                std::swap(current->nama, current->next->nama);
                std::swap(current->matkulList, current->next->matkulList);
                std::swap(current->accMatkulList, current->next->accMatkulList);
                std::swap(current->isAccepted, current->next->isAccepted);
                std::swap(current->kelas, current->next->kelas);

                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void Maindosen::tampilkanMahasiswa(){
    ui->tampilmhs->clear();
    sortMahasiswa();

    Mahasiswa* current = headMahasiswa;
    if (current == nullptr) {
        ui->tampilmhs->appendPlainText("Belum ada mahasiswa yang terdaftar.");
    } else {
        ui->tampilmhs->appendPlainText("=== Daftar Mahasiswa (Terurut berdasarkan NIM) ===");
        while (current != nullptr) {
            QString line = "NIM: " + current->nim +
                           ", Nama: " + current->nama +
                           ", Status: " + (current->isAccepted ? "Sudah di-ACC" : "Belum di-ACC") +
                           ", Kelas: " + (current->kelas.empty() ? "Belum ditentukan" : QString::fromStdString(current->kelas));
            ui->tampilmhs->appendPlainText(line);
            current = current->next;
        }
    }

    treeRoot = nullptr;
    current = headMahasiswa;
    while (current != nullptr) {
        insertTree(treeRoot, current->nim,current->nama,current->matkulList);
        current = current->next;
    }

    ui->tampilmhs->appendPlainText("\n=== Tree Hirarki Mahasiswa dan Mata Kuliah ===");
    tampilkanTree(treeRoot);
}
void Maindosen::gobacktomain(){
    this->close();
    QWidget *parentWindow = this->parentWidget();
    if(parentWindow)
        parentWindow->show();
}
void Maindosen::on_btnKembali_clicked(){
    this->close();
    QWidget *parentWindow = this->parentWidget();
    if (parentWindow)
        parentWindow->show();
}
