/*
 * Author: Pan Zhao
 * Email : panzhao12@gmail.com
*/


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lcdNumber->display("00:00:00");

    timer = new QTimer();
    timer->setTimerType(Qt::PreciseTimer);
    connect(timer, SIGNAL(timeout()), this, SLOT(refreshTime()));

    initialTime = new QTime(0, 0, 0);
    currentTime = new QTime(0, 0, 0);

    startTimeFlag = true;

    connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(startMyTimer(bool)));
    connect(ui->stopButton, SIGNAL(clicked(bool)), this, SLOT(stopMyTimer(bool)));
    connect(ui->resetButton, SIGNAL(clicked(bool)), this, SLOT(resetMyTimer(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete initialTime;
    delete currentTime;
}

void MainWindow::startMyTimer(bool)
{
    if(startTimeFlag){
        timer->start(100);
    }

    startTimeFlag = false;
}

void MainWindow::refreshTime()
{
    *initialTime = initialTime->addMSecs(100);
    currentTime = initialTime;
    ui->lcdNumber->display(currentTime->toString());
}

void MainWindow::stopMyTimer(bool)
{
    startTimeFlag = true;
    timer->stop();
}

void MainWindow::resetMyTimer(bool)
{
    startTimeFlag = true;
    timer->stop();
    initialTime = new QTime(0, 0, 0);
    ui->lcdNumber->display(initialTime->toString());
}
