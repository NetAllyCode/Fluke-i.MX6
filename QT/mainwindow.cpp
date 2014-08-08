#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMessageBox>
#include <QFileDialog>
#include <QPixmap>
#include <QTimer>

#define BATTERY_TIMER_TICK 750
#define LIVE_DATA_TICK 500

#define NUM_NETWORK_ROWS 10
#define NUM_NETWORK_COLUMNS 6

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   //const QString ssid_list[10] = {QString("Battle Mountain Crestron"), QString("CarlE4200"), QString("Cisco4400"), QString("Danaher TM"), QString("Demo"), QString("FNET WPA TEST"), QString("Weboshi"), QString("Authorized Guest"), QString("mfgTestSSID"), QString("[Hidden]")};
    ui->setupUi(this);

    ui->comboBox->addItem("Default*");
    ui->comboBox->addItem("Custom 1");
    ui->comboBox->addItem("Custom 2");
    ui->comboBox->addItem("Weboshi");

    model = new QStandardItemModel(NUM_NETWORK_ROWS,NUM_NETWORK_COLUMNS,this);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("SSID")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Signal")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("SNR")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("Band")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QString("Security")));
    model->setHorizontalHeaderItem(5, new QStandardItem(QString("APs")));


    ui->tableView->setModel(model);

    QTimer *batteryTimer = new QTimer(this);
    connect(batteryTimer, SIGNAL(timeout()), this, SLOT(updateBattery()));
    batteryTimer->start(BATTERY_TIMER_TICK);

    QTimer *liveDataSimulator = new QTimer(this);
    connect(liveDataSimulator, SIGNAL(timeout()), this, SLOT(updateLiveData()));
    liveDataSimulator->start(LIVE_DATA_TICK);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLiveData()
{
    const QString ssid_list[10] = {QString("Battle Mountain Crestron"), QString("CarlE4200"), QString("Cisco4400"), QString("Danaher TM"), QString("Demo"), QString("FNET WPA TEST"), QString("Weboshi"), QString("Authorized Guest"), QString("mfgTestSSID"), QString("[Hidden]")};

    int i;
    for(i = 0; i < NUM_NETWORK_ROWS; i++)
    {
        QStandardItem *ssid = new QStandardItem(ssid_list[i]);
        QStandardItem *row0 = new QStandardItem(QString::number(random(-120, -30)));
        QStandardItem *row1 = new QStandardItem(QString::number(random(25, 100)));
        QStandardItem *row2 = new QStandardItem(QString("Ch. %1").arg(random(1,12)));
        QStandardItem *row3;
        switch(random(0,4))
        {
            case 1:
                row3 = new QStandardItem(QString("OPEN"));
                break;
            case 2:
                row3 = new QStandardItem(QString("WEP"));
                break;
            case 3:
                row3 = new QStandardItem(QString("WPA"));
                break;
            case 4:
                row3 = new QStandardItem(QString("WPA2"));
                break;
            default:
                row3 = new QStandardItem(QString("OPEN"));
                break;
        }
        QStandardItem *row4 = new QStandardItem(QString::number(random(1,10)));
        model->setItem(i,0,ssid);
        model->setItem(i,1,row0);
        model->setItem(i,2,row1);
        model->setItem(i,3,row2);
        model->setItem(i,4,row3);
        model->setItem(i,5,row4);
        ui->tableView->setModel(model);
    }
}

int MainWindow::random(int min, int max)
{
    return  (qrand() % (max-min)+1) + min;
}

void MainWindow::updateBattery()
{
    switch(battery_state)
    {
        case 0:
            ui->label->setPixmap(QPixmap(":/new/prefix1/icons/UI/battery_0.bmp"));
            battery_state = 1;
            break;
        case 1:
            ui->label->setPixmap(QPixmap(":/new/prefix1/icons/UI/battery_20.bmp"));
            battery_state = 2;
            break;
        case 2:
            ui->label->setPixmap(QPixmap(":/new/prefix1/icons/UI/battery_40.bmp"));
            battery_state = 3;
            break;
        case 3:
            ui->label->setPixmap(QPixmap(":/new/prefix1/icons/UI/battery_60.bmp"));
            battery_state = 4;
            break;
        case 4:
            ui->label->setPixmap(QPixmap(":/new/prefix1/icons/UI/battery_80.bmp"));
            battery_state = 5;
            break;
        case 5:
            ui->label->setPixmap(QPixmap(":/new/prefix1/icons/UI/battery_100.bmp"));
            battery_state = 0;
            break;
    }
}

void MainWindow::on_pushButton_4_clicked() //Auto test
{
    QMessageBox about;


        about.setStandardButtons(QMessageBox::Ok);
        about.setDefaultButton(QMessageBox::Ok);
        about.setIconPixmap(QPixmap(":/new/prefix1/icons/UI/autotest_dialog.bmp"));
        about.show();
        about.exec();
}

void MainWindow::on_pushButton_4_pressed() //Auto Test
{
    ui->pushButton_4->setIcon(QIcon(QPixmap(":/new/prefix1/icons/UI/autotest_down.bmp")));
}

void MainWindow::on_pushButton_4_released() //Auto Test
{
    ui->pushButton_4->setIcon(QIcon(QPixmap(":/new/prefix1/icons/UI/autotest.bmp")));
}

void MainWindow::on_pushButton_5_pressed() //Tools
{
    ui->pushButton_5->setIcon(QIcon(QPixmap(":/new/prefix1/icons/UI/tools_down.bmp")));
}

void MainWindow::on_pushButton_5_released() //Tools
{
    ui->pushButton_5->setIcon(QIcon(QPixmap(":/new/prefix1/icons/UI/tools.bmp")));
}

void MainWindow::on_pushButton_6_pressed() //Save
{
    ui->pushButton_6->setIcon(QIcon(QPixmap(":/new/prefix1/icons/UI/save_down.bmp")));
}

void MainWindow::on_pushButton_6_released() //Save
{
    ui->pushButton_6->setIcon(QIcon(QPixmap(":/new/prefix1/icons/UI/save.bmp")));
}

void MainWindow::on_pushButton_7_pressed() //Capture
{
    ui->pushButton_7->setIcon(QIcon(QPixmap(":/new/prefix1/icons/UI/capture_down.bmp")));
}

void MainWindow::on_pushButton_7_released() //Capture
{
    ui->pushButton_7->setIcon(QIcon(QPixmap(":/new/prefix1/icons/UI/capture.bmp")));
}

void MainWindow::on_pushButton_6_clicked() //Save
{
    QFileDialog::getOpenFileName(this, tr("Save Capture File"), "/root", tr("Capture Files (*.cap)"));
}

void MainWindow::on_pushButton_2_clicked() //Clear
{
    QMessageBox about;


        about.setStandardButtons(QMessageBox::Ok);
        about.setDefaultButton(QMessageBox::Ok);
        about.setIconPixmap(QPixmap(":/new/prefix1/icons/UI/clear.bmp"));
        about.show();
        about.exec();
}

void MainWindow::on_pushButton_3_clicked() //Load Profile
{
    QFileDialog::getOpenFileName(this, tr("Load Profile"), "/root", tr("Profiles (*.profile)"));
}

void MainWindow::on_pushButton_pressed() //Back
{
    ui->pushButton->setIcon(QIcon(QPixmap(":/new/prefix1/icons/UI/wont_back_down.bmp")));
}

void MainWindow::on_pushButton_released() //Back
{
    ui->pushButton->setIcon(QIcon(QPixmap(":/new/prefix1/icons/UI/back.bmp")));
}

void MainWindow::on_pushButton_2_pressed() //Refresh
{
    ui->pushButton_2->setIcon(QIcon(QPixmap(":/new/prefix1/icons/UI/refresh_down.bmp")));
}

void MainWindow::on_pushButton_2_released() //Refresh
{
    ui->pushButton_2->setIcon(QIcon(QPixmap(":/new/prefix1/icons/UI/refresh.bmp")));
}

void MainWindow::on_pushButton_3_released() //Profile
{
    ui->pushButton_3->setIcon(QIcon(QPixmap(":/new/prefix1/icons/UI/profile.bmp")));
}

void MainWindow::on_pushButton_3_pressed() //Profile
{
    ui->pushButton_3->setIcon(QIcon(QPixmap(":/new/prefix1/icons/UI/profile_down.bmp")));
}
