#include <QMainWindow>
#include "mainmahasiswa.h"
#include "mainadmin.h"
#include "maindosen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnMahasiswa_clicked();
    void on_btnAdmin_clicked();
    void on_btnDosen_clicked();

private:
    Ui::MainWindow *ui;
    Mainmahasiswa *mhsWindow;
    Mainadmin *adminWindow;
    Maindosen *dosenWindow;
};
