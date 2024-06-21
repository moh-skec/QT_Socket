#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->port->setText("1500");
}

MainWindow::~MainWindow()
{
    if(socket)
    {
        delete socket;
    }

    delete ui;
}

void MainWindow::socket_connected()
{
    ui->output->append("Connected!");
}

void MainWindow::socket_readyRead()
{
    QByteArray data = socket->readAll();
    ui->output->append("Data: " + data);
}

void MainWindow::socket_bytesWritten()
{
    ui->output->append("Data was written!");
}

void MainWindow::socket_disconnected()
{
    ui->output->append("Disconnected!");
}

void MainWindow::on_connect_clicked()
{
    if (socket)
    {
        ui->output->append("Already connected!");
    } else
    {
        ui->output->append("Connecting...");

        socket = new QTcpSocket();
        socket->connectToHost("127.0.0.1", ui->port->text().toInt());

        connect(socket, &QTcpSocket::connected, this, &MainWindow::socket_connected);
        connect(socket, &QTcpSocket::readyRead, this, &MainWindow::socket_readyRead);
        connect(socket, &QTcpSocket::bytesWritten, this, &MainWindow::socket_bytesWritten);
        connect(socket, &QTcpSocket::disconnected, this, &MainWindow::socket_disconnected);
    }

}


void MainWindow::on_disconnect_clicked()
{
    if (!socket)
    {
        ui->output->append("Not connected yet!");
    } else
    {
        delete socket;
        socket = nullptr;
        ui->output->append("Disconnected!");
    }

}


void MainWindow::on_send_clicked()
{
    if (socket)
    {
        socket->write(ui->input->toPlainText().toUtf8());
        ui->output->append("Data was sent!");
    }

}

