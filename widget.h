#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
class QUdpSocket;
class TcpServer;

enum MessageType{Message,NewParticipant,ParticipantLeft,FileName,Refuse};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void newParticipant(QString userName,QString localHostName,QString ipAdress);
    void participantLeft(QString userName,QString localHostName,QString time);
    void sendMessage(MessageType type,QString serverAddress = "");
    QString getIP();
    QString getUserName();
    QString getMessage();

    void hasPendingFile(QString userName,QString serverAddress,QString clientAddress,QString fileName);

    bool saveFile(const QString &fileName);//保存聊天记录
    void closeEvent(QCloseEvent *event);

private slots:
    void processPendingDatagrams();

    void getFileName(QString);

    void on_sendButton_clicked();

    void on_sendToolButton_clicked();

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_sizeComboBox_currentIndexChanged(const QString &arg1);

    void on_boldToolButton_clicked(bool checked);

    void on_italicToolButton_clicked(bool checked);

    void on_underlineToolButton_clicked(bool checked);

    void on_colorToolButton_clicked();

    void on_saveToolButton_clicked();

    void on_clearToolButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;
    qint16 port;

    QString fileName;
    TcpServer *server;

    QColor color;//字体颜色
};
#endif // WIDGET_H
