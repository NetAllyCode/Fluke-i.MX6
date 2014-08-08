/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTabWidget *tabWidget;
    QWidget *Network;
    QTableView *tableView;
    QWidget *Channel;
    QLabel *label_4;
    QWidget *APs;
    QWidget *Clients;
    QLabel *label_6;
    QFrame *frame;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QFrame *line_2;
    QFrame *line;
    QFrame *frame_2;
    QComboBox *comboBox;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 718);
        QPalette palette;
        QBrush brush(QColor(170, 170, 127, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        MainWindow->setPalette(palette);
        MainWindow->setIconSize(QSize(0, 0));
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QPalette palette1;
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        centralWidget->setPalette(palette1);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 61, 91));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icons/UI/battery_half.bmp")));
        label->setScaledContents(true);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 10, 73, 75));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icons/UI/back.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(80, 80));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 10, 80, 75));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/UI/refresh.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(80, 80));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(280, 10, 80, 71));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icons/UI/profile.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(80, 80));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 101, 600, 521));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(202, 202, 202, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush3(QColor(0, 0, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        tabWidget->setPalette(palette2);
        QFont font;
        font.setPointSize(28);
        font.setItalic(false);
        tabWidget->setFont(font);
        tabWidget->setAutoFillBackground(true);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setIconSize(QSize(89, 41));
        Network = new QWidget();
        Network->setObjectName(QString::fromUtf8("Network"));
        Network->setMinimumSize(QSize(0, 0));
        tableView = new QTableView(Network);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 600, 471));
        tableView->setFrameShape(QFrame::NoFrame);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setAutoScroll(false);
        tableView->setSortingEnabled(true);
        tabWidget->addTab(Network, QString());
        Channel = new QWidget();
        Channel->setObjectName(QString::fromUtf8("Channel"));
        label_4 = new QLabel(Channel);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 601, 461));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icons/channels.bmp")));
        label_4->setScaledContents(true);
        tabWidget->addTab(Channel, QString());
        APs = new QWidget();
        APs->setObjectName(QString::fromUtf8("APs"));
        tabWidget->addTab(APs, QString());
        Clients = new QWidget();
        Clients->setObjectName(QString::fromUtf8("Clients"));
        label_6 = new QLabel(Clients);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 0, 601, 461));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icons/clients.BMP")));
        label_6->setScaledContents(true);
        tabWidget->addTab(Clients, QString());
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 620, 600, 100));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(50, 10, 80, 80));
        QFont font1;
        font1.setPointSize(14);
        pushButton_4->setFont(font1);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/icons/UI/autotest.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setIconSize(QSize(80, 80));
        pushButton_4->setCheckable(false);
        pushButton_4->setChecked(false);
        pushButton_4->setFlat(false);
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(190, 10, 80, 80));
        pushButton_5->setFont(font1);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/icons/UI/tools.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon4);
        pushButton_5->setIconSize(QSize(80, 80));
        pushButton_6 = new QPushButton(frame);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(330, 10, 80, 80));
        pushButton_6->setFont(font1);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/icons/UI/save.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon5);
        pushButton_6->setIconSize(QSize(80, 80));
        pushButton_7 = new QPushButton(frame);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(470, 10, 80, 80));
        pushButton_7->setFont(font1);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/icons/UI/capture.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon6);
        pushButton_7->setIconSize(QSize(80, 80));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 80, 601, 20));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        QBrush brush4(QColor(190, 190, 190, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        line_2->setPalette(palette3);
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(4);
        line_2->setFrameShape(QFrame::HLine);
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(60, -10, 10, 100));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        line->setPalette(palette4);
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(4);
        line->setFrameShape(QFrame::VLine);
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(390, 10, 201, 71));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(2);
        comboBox = new QComboBox(frame_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 40, 181, 23));
        QFont font2;
        font2.setPointSize(24);
        comboBox->setFont(font2);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 0, 181, 41));
        QPalette palette5;
        QBrush brush5(QColor(170, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        label_2->setPalette(palette5);
        label_2->setTextFormat(Qt::RichText);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Snackers Simulator", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Network), QApplication::translate("MainWindow", "Network", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Channel), QApplication::translate("MainWindow", "Channel", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(APs), QApplication::translate("MainWindow", "APs", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Clients), QApplication::translate("MainWindow", "Clients", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt;\">Current Profile:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
