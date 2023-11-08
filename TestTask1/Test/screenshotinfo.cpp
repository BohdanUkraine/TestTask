#include "screenshotinfo.h"
#include "ui_screenshotinfo.h"
#include <QPicture>

ScreenshotInfo::ScreenshotInfo(QImage image, float percent, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScreenshotInfo)
{
    ui->setupUi(this);

    this->percent = percent;
    myPicture = new QPixmap(QPixmap::fromImage(image).scaled(300,100,Qt::KeepAspectRatio));
    ui->Image->setPixmap(*myPicture);
    ui->percent->setText(QString::number(percent));
}

ScreenshotInfo::~ScreenshotInfo()
{
    delete ui;
}
