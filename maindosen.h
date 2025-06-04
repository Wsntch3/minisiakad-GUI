#ifndef MAINDOSEN_H
#define MAINDOSEN_H

#include "common.h"

#include <QMainWindow>

namespace Ui {
class Maindosen;
}

class Maindosen : public QMainWindow
{
    Q_OBJECT

public:
    explicit Maindosen(QWidget *parent = nullptr);
    ~Maindosen();
    void accMatkul();
    void sortMahasiswa();
    void tampilkanMahasiswa();
    void tampilkanTree(TreeNode* root);
    void carimahasiswa();
    void btn_accMatkul_clicked();
    void btn_sortMahasiswa_clicked();
    void btn_carimahasiswa_clicked();
    void on_btnKembali_clicked();
    void gobacktomain();

private:
    Ui::Maindosen *ui;
    QWidget *menuUtama;
};

#endif // MAINDOSEN_H
