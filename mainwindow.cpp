#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QLCDNumber>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->lcdNumber->setPalette(Qt::red);
//    auto palette = ui->lcdNumber->palette();
//    palette.setColor(palette.WindowText, Qt::blue);
//    palette.setColor(palette.BrightText, Qt::yellow);
//    ui->lcdNumber->setPalette(palette);

    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat );
    ui->lcdNumber->setDigitCount(8);

    Date_Time = new QTimer();

    connect(Date_Time, SIGNAL(timeout()), this, SLOT(Date_Time_Show_Slot()));

    Date_Time->setInterval(1000);
    Date_Time->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Date_Time_Show_Slot()
{
    if(trigger == false){
        QString CurrentTime = QDateTime::currentDateTime().toString("HH:mm:ss");

        ui->lcdNumber->display(CurrentTime);

        this->trigger = true;
    }else{
        QString CurrentTime = QDateTime::currentDateTime().toString("HH mm ss");

        ui->lcdNumber->display(CurrentTime);

        this->trigger = false;
    }
}


