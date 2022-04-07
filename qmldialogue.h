#ifndef QMLDIALOGUE_H
#define QMLDIALOGUE_H

#include <QObject>
#include <QDebug>

#include <QByteArray>
#include <QImage>
#include <QString>

#include <QSslSocket>
#include <QNetworkReply>
#include <QTextCodec>
#include <QEventLoop>

#include "QZXing/QZXing.h"

class qmldialogue : public QObject
{
    Q_OBJECT
public:
    explicit qmldialogue(QObject *parent = nullptr);
    Q_INVOKABLE void debugText();
    Q_INVOKABLE QString scanQR(); // в скобках входящяя картинка (с камеры)
    Q_INVOKABLE QString readPage(QString page);
    Q_INVOKABLE QString getFullLink();
private:
    QString fullLink;

signals:

};

#endif // QMLDIALOGUE_H
