/*
 * Author: Pan Zhao
 * Email : panzhao12@gmail.com
*/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTime *initialTime;
    QTime *currentTime;
    bool startTimeFlag;

private slots:
    void startMyTimer(bool);
    void stopMyTimer(bool);
    void resetMyTimer(bool);
    void refreshTime();
};
#endif // MAINWINDOW_H
