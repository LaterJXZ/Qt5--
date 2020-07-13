#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDialog>
#include <QTime>

namespace Ui {
class TcpServer;
}
class QFile;
class QTcpServer;
class QTcpSocket;

class TcpServer : public QDialog
{
    Q_OBJECT

public:
    explicit TcpServer(QWidget *parent = nullptr);
    ~TcpServer();
    void initServer();
    void refused();

protected:
    void closeEvent(QCloseEvent *);

private:
    Ui::TcpServer *ui;

    qint16 tcpPort;
    QTcpServer *tcpServer;
    QString fileName;
    QString theFileName;
    QFile *localFile;
    qint64 totalBytes;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    qint64 payloadSize;
    QByteArray outBlock;
    QTcpSocket *clientConnection;
    QTime time;

private slots:
    void sendMessage();
    void updateClientProgress(qint64 numBytes);

    void on_serverOpenButton_clicked();

    void on_serverSendButton_clicked();

    void on_serverCloseButton_clicked();

signals:
    void sendFileName(QString fileName);
};

#endif // TCPSERVER_H
