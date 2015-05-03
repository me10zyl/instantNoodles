#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QTimer>
#include <QMessageBox>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showTime(ui->timeEdit->time());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_timeEdit_timeChanged(const QTime &time)
{
    showTime(time);
}

void MainWindow::showTime(const QTime &time) const
{
    int seconds = time.minute() * 60 + time.second();
    cout<< time.second() << endl;
    ui->lcd->display(seconds);
}

void MainWindow::showTimeInt(int seconds) const
{
     ui->lcd->display(seconds);
}

void MainWindow::updateTime()
{
    if(time - 1 < 0)
    {
        QMessageBox *dialog = new QMessageBox();
        //dialog->setIcon(QMessageBox::Warning);
        dialog->setWindowTitle("泡面好了!");
        dialog->setText("别玩啦，该吃泡面了！");
        dialog->setIconPixmap(QPixmap("icon.png"));
        dialog->setModal(true);
        this->setVisible(false);
        WId wid = dialog->winId();
        if(dialog->exec())
        {
            cout << "haha" << endl;
            exit(0);
        }

        //dialog->warning(this,"该吃泡面啦！","别玩了，该吃泡面了！", QMessageBox::Ok);
        //QAbstractButton *button = new QAbstractButton(this);
        //connect(dialog,buttonClicked(button),this,dialogButtonClicked(button));
        return;
    }
    showTimeInt(--time);
}

void MainWindow::dialogButtonClicked() const
{
cout<< "ok!" << endl;
}

void MainWindow::on_pushButton_clicked()
{
    time = ui->lcd->value();
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    timer->start(1000);
    ui->pushButton->setEnabled(false);
    ui->timeEdit->setEnabled(false);
}
