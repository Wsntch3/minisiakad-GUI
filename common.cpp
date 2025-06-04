#include "common.h"
QueueNode* queueFront = nullptr;
QueueNode* queueRear = nullptr;
TreeNode* treeRoot = nullptr;
Mahasiswa* headMahasiswa = nullptr;
StackNode* undoStack = nullptr;
HashNode* hashTable[100];

Matkul daftarMatkul[6] = {
    {1, "Matematika Diskrit", 3, nullptr},
    {2, "Pemrograman Berorientasi Objek", 3, nullptr},
    {3, "Struktur Data", 4, nullptr},
    {4, "Sistem Operasi", 3, nullptr},
    {5, "Statistika", 2, nullptr},
    {6, "PPKN", 2, nullptr}
};


int sksMatkul[6] = {3, 3, 4, 3, 2, 2};
void iniHashTable() {
    for (int i = 0; i < 100; ++i) {
        hashTable[i] = nullptr;
    }
}
int hashFunction(QString nim) {
    int hash = 0;
    for (int i = 0; i < nim.length(); ++i) {
        hash += nim[i].unicode();
    }
    return hash % 100;
}

Matkul* buatMatkul(int id, std::string nama, int sks) {
    Matkul* newMatkul = new Matkul;
    newMatkul->id = id;
    newMatkul->nama = nama;
    newMatkul->sks = sks;
    newMatkul->next = nullptr;
    return newMatkul;
}

Mahasiswa* cariMahasiswa(QString nim) {
    int index = hashFunction(nim);
    HashNode* current = hashTable[index];

    while (current != nullptr) {
        if (current->mahasiswa->nim == nim) {
            return current->mahasiswa;
        }
        current = current->next;
    }
    return nullptr;
}
void insertTree(TreeNode* &root, QString nim, QString nama, Matkul* matkulList) {
    if (root == nullptr) {
        root = new TreeNode;
        root->nim = nim.toStdString();
        root->nama = nama.toStdString();
        root->matkulList = matkulList;
        root->left = nullptr;
        root->right = nullptr;
    } else if (nim < QString::fromStdString(root->nim)) {
        insertTree(root->left, nim, nama, matkulList);
    } else if (nim > QString::fromStdString(root->nim)) {
        insertTree(root->right, nim, nama, matkulList);
    }
}
