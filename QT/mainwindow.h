#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int battery_state = 0;
    QStandardItemModel *model;
    //const QString ssid_list[10];

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_4_pressed();

    void on_pushButton_4_released();

    void on_pushButton_5_pressed();

    void on_pushButton_5_released();

    void on_pushButton_6_pressed();

    void on_pushButton_6_released();

    void on_pushButton_7_pressed();

    void on_pushButton_7_released();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_pushButton_3_released();

    void on_pushButton_3_pressed();

    void updateBattery();

    void updateLiveData();

    int random(int min, int max);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
