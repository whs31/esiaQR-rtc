#include "qmldialogue.h"

qmldialogue::qmldialogue(QObject *parent) : QObject(parent)
{

}

void qmldialogue::debugText()
{
    qDebug()<<"Debug succesful";
}

QString qmldialogue::scanQR()
{
    qDebug()<<"Trying to scan qr code from input pixmap...";

    QImage qrCodeimageToDecode(":/qrsamples/sampletier1.png");
    QZXing decoder;
    decoder.setDecoder(QZXing::DecoderFormat_QR_CODE);

    QString resultQrCode = decoder.decodeImage(qrCodeimageToDecode);
    QString token;
    if(resultQrCode.startsWith("http"))
    {
        //это ссылка
        qDebug()<<"Scan result: hyperlink found. Verifying hyperlink...";
        if(resultQrCode.contains("gosuslugi.ru/covid-cert"))
        {
            qDebug()<<"Hyperlink verified. Result: "<<resultQrCode;
            qDebug()<<"\nSSL status: "<<QSslSocket::supportsSsl();
            if(!QSslSocket::supportsSsl())
            {
                qDebug()<<"SSL Error. Aborting...";
                return "err";
            } else {
                //continue url work
                token = resultQrCode;
                token.remove(0, 43);
                token.chop(36);
                fullLink = resultQrCode;
                return token;
            }
        } else {
            qDebug()<<"Hyperlink non-verified. Aborting...";
            return "err";
        }
    } else {
        qDebug()<<"Scan result: no hyperlink found. Aborting...";
        return "err";
    }
}

QString qmldialogue::getFullLink()
{
    return fullLink;
}

QString qmldialogue::readPage(QString page)
{
    QString url = "https://my link here";
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(url)));
    QEventLoop event;
    connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    QByteArray bytes = response->readAll();
    QString str = QString::fromUtf8(bytes.data(), bytes.size());
    int statusCode = response->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug()<<str;
    qDebug() << QVariant(statusCode).toString();
    return str;
}
