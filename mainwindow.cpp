#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        ui->port->addItem(info.portName());

//    connect(&thread, &MasterThread::response, this, &MainWindow::showResponse);
//    connect(&thread, &MasterThread::error, this, &MainWindow::processError);
//    connect(&thread, &MasterThread::timeout, this, &MainWindow::processTimeout);

    connect(&thread, &SlaveThread::request, this, &MainWindow::showResponse);
    connect(&thread, &SlaveThread::error, this, &MainWindow::processError);
    connect(&thread, &SlaveThread::timeout, this, &MainWindow::processTimeout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{
    QString currentPortName = ui->port->currentText();

//    QSerialPort serial;
//    serial.setPortName(currentPortName);
//    serial.setBaudRate(ui->baud->currentText().toInt());
//    if (!serial.open(QIODevice::ReadWrite)) {
//        qDebug() << tr("Can't open %1, error code %2")
//                   .arg(currentPortName).arg(serial.error());
//        return;
//    }

    thread.startSlave(currentPortName,
                       10000,
                        "test");
}

void MainWindow::on_stop_clicked()
{

}

void MainWindow::showResponse(const QString &s)
{
    long long tmp = 0x03FELL | ((ui->comboBox_time->currentIndex() + 0x31) << 16);
    tmp |= ((ui->comboBox_count->currentIndex() + 0x31) << 24);
    tmp |= 0xffLL << 32;
}

void MainWindow::processError(const QString &s)
{
    qDebug() << __FUNCTION__ << s;
}

void MainWindow::processTimeout(const QString &s)
{
    qDebug() << __FUNCTION__ << s;

}
