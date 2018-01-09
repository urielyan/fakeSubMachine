#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "masterthread.h"
#include "slavethread.h"

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
    void on_start_clicked();

    void on_stop_clicked();
private slots:
    void showResponse(const QByteArray &s);
    void processError(const QString &s);
    void processTimeout(const QString &s);

private:
    Ui::MainWindow *ui;
    //MasterThread thread;
    SlaveThread thread;
};

#endif // MAINWINDOW_H
