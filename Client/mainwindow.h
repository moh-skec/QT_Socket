#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void socket_connected();
    void socket_readyRead();
    void socket_bytesWritten();
    void socket_disconnected();

private slots:
    void on_connect_clicked();

    void on_disconnect_clicked();

    void on_send_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket = nullptr;
};
#endif // MAINWINDOW_H
