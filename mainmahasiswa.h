#ifndef MAINMAHASISWA_H
#define MAINMAHASISWA_H
#include "common.h"

#include <QMainWindow>

namespace Ui {
class Mainmahasiswa;
}

class Mainmahasiswa : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mainmahasiswa(QWidget *parent = nullptr);
    ~Mainmahasiswa();
    void tambahmatkul();
    void undomatkul();
    void tampilkanmatkul();
    void tampilkandaftarmatkul();
    void hitungsks();
    void btn_tambahMatkul_clicked();
    void on_btnPageTambahMatkul_clicked();
    void setNimMahasiswa(const QString &nim);
    void tampilkandaftar();
    void tambahkequeue(QString nim, int idMatkul);
    void on_btnKembali_clicked();
    void gobacktomain();


private:
    Ui::Mainmahasiswa *ui;
    QString nimMahasiswa;
    Mahasiswa* findMahasiswa();
    QWidget *menuUtama;
};

#endif // MAINMAHASISWA_H
