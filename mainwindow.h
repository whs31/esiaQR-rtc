#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QDebug>
#include <QByteArray>
#include <QImage>
#include <QFileDialog>
#include <QFont>
#include <QTextCodec>
#include <QGraphicsScene>

#include <QXmlStreamReader>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

#include <QSslSocket>

#include <QTextBrowser>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bt_decodeImage_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
        QNetworkReply *response;
};
#endif // MAINWINDOW_H
