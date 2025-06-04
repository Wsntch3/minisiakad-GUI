#ifndef COMMON_H
#define COMMON_H

#include <QString>
using std::string;

struct Matkul {
    int id;
    string nama;
    int sks;
    Matkul* next;
};

struct StackNode {
    Matkul data;
    StackNode* next;
};

struct QueueNode {
    QString nim;
    Matkul matkul;
    QueueNode* next;
};

struct Mahasiswa {
    QString nim;
    QString nama;
    Matkul* matkulList;
    Matkul* accMatkulList;
    bool isAccepted;
    string kelas;
    Mahasiswa* next;
};

struct HashNode {
    Mahasiswa* mahasiswa;
    HashNode* next;
};

struct TreeNode {
    string nim;
    string nama;
    Matkul* matkulList;
    TreeNode* left;
    TreeNode* right;
};

extern QueueNode* queueFront;
extern QueueNode* queueRear;
extern QueueNode* queueFrontAcc;
extern QueueNode* queueRearAcc;
extern TreeNode* treeRoot;
extern Mahasiswa* headMahasiswa;
extern StackNode* undoStack;
extern Matkul daftarMatkul[6];
extern int sksMatkul[6];
extern HashNode* hashTable[100];

int hashFunction(QString key);
Matkul* buatMatkul(int id, string nama, int sks);
void insertTree(TreeNode* &root, QString prodi, QString semester, Matkul* matkul);
Mahasiswa* cariMahasiswa(QString nim);

#endif
