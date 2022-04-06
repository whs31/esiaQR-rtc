#ifndef QMLDIALOGUE_H
#define QMLDIALOGUE_H

#include <QObject>
#include <QDebug>

#include <QByteArray>
#include <QImage>
#include <QString>

#include <QSslSocket>

#include "QZXing/QZXing.h"

class qmldialogue : public QObject
{
    Q_OBJECT
public:
    explicit qmldialogue(QObject *parent = nullptr);
    Q_INVOKABLE void debugText();
    Q_INVOKABLE QString scanQR(); // в скобках входящяя картинка (с камеры)

signals:

};

#endif // QMLDIALOGUE_H
