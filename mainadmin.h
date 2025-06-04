#ifndef MAINADMIN_H
#define MAINADMIN_H

#include <QMainWindow>

namespace Ui {
class Mainadmin;
}

class Mainadmin : public QMainWindow
{
    Q_OBJECT
public:
    explicit Mainadmin(QWidget *parent = nullptr);
    ~Mainadmin();
    void tambahkekelas();
    void tambahMahasiswa();
    void on_btnKembali_clicked();
    void gobacktomain();


private:
    Ui::Mainadmin *ui;
    QWidget *menuUtama;
};

#endif // MAINADMIN_H
