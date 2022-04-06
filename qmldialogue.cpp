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
    qDebug()<<"Scan result: "<<resultQrCode;
    qDebug()<<"\nSSL status: "<<QSslSocket::supportsSsl();
    return 0;
}
