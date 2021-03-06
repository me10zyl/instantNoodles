#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_timeEdit_timeChanged(const QTime &time);

    void on_pushButton_clicked();
     void updateTime();

private:
    Ui::MainWindow *ui;
    int time;
    void showTime(const QTime &time) const;
    void showTimeInt(int seconds) const;
    void dialogButtonClicked() const;
};

#endif // MAINWINDOW_H
