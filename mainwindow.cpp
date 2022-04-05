#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QZXing/QZXing.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<QSslSocket::supportsSsl();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bt_decodeImage_clicked()
{
    QGraphicsScene *scene;
    QPixmap image;

    QImage qrCodeimageToDecode(":/qr.jpg");
    qDebug()<<qrCodeimageToDecode.size();
    QZXing decoder;
    decoder.setDecoder(QZXing::DecoderFormat_QR_CODE);

    QString resultQrCode = decoder.decodeImage(qrCodeimageToDecode);

    QFont bold8pxfont = ui->lbl_qrHyperlink->font();
    bold8pxfont.setPointSize(8);
    bold8pxfont.setBold(true);

    ui->lbl_qrHyperlink->setText(resultQrCode);
    ui->lbl_qrHyperlink->setAlignment(Qt::AlignRight);
    ui->lbl_qrHyperlink->setFont(bold8pxfont);
    qDebug()<<resultQrCode;
    image.load(":/qr.jpg");
    QPixmap pixmapScaled = image.scaled(QSize(image.width()/2,image.height()/2),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    scene = new QGraphicsScene(this);
    scene->addPixmap(pixmapScaled);
    scene->setSceneRect(pixmapScaled.rect());

    ui->graphicsView->setScene(scene);

    QString lang = "ru";
    resultQrCode.chop(2);
    QString url = resultQrCode+lang;
    qDebug()<<url;

    QFile file(url);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream(&file);
    qDebug()<<stream.readAll();
}
