#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "screenshotinfo.h"
#include "threadcalc.h"
#include <QPixmap>
#include <QLabel>
#include <QScreen>
#include <QPixmap>
#include <QImage>
#include <QCryptographicHash>
#include <QByteArray>
#include <QThread>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = new DataBaseOperations("thread1");

    if(db->getCount() == 0){
        auto geom = this->screen()->geometry();
        QPixmap qpx_pixmap = this->screen()->grabWindow(0, geom.x(), geom.y(), geom.width(), geom.height());
        QImage img = qpx_pixmap.toImage();
        QString fileName = "imgs/0.png"; //filename
        img.save(fileName);
        QCryptographicHash *data = new QCryptographicHash(QCryptographicHash::Md5);
        data->addData(QString::number(img.cacheKey()).toUtf8());
        db->insertData(data->result(), 0, fileName);
    }
    loadWidgetsFromDB();

    th = new ThreadCalc(this);
}

MainWindow::~MainWindow()
{
    th->quit();
    delete ui;
}

void MainWindow::loadWidgetsFromDB(){
    int n = db->getCount();
    for(int i=0; i<n; i++){

        QImage tmpImage;
        float tmpPercent;
        db->getDataAt(tmpImage, tmpPercent, i);

        ScreenshotInfo *info = new ScreenshotInfo(tmpImage, tmpPercent, this);
        addWidgetToGrid(info);
        //info->show();
    }
}

void MainWindow::addWidgetToGrid(ScreenshotInfo *widget){



    ScreenshotInfo *info = new ScreenshotInfo(widget->myPicture->toImage(), widget->percent, this);

    delete(widget);

    if(ui->gridLayout->count() == 0){
        ui->gridLayout->addWidget(info,0,0);
        return;
    }

    info->show();

    QLayoutItem *tmp;
    QLayoutItem *tmp1;

    tmp = ui->gridLayout->itemAt(0);
    ui->gridLayout->replaceWidget(tmp->widget(), info);
    ui->gridLayout->removeItem(tmp);
    ui->gridLayout->addItem(tmp,1,0);

    int i=1;
    while (i<ui->gridLayout->count()){
        tmp1=tmp;
        tmp = ui->gridLayout->itemAt(i);
        ui->gridLayout->replaceWidget(tmp->widget(), tmp1->widget());
        ui->gridLayout->removeItem(tmp);
        ui->gridLayout->addItem(tmp,i+1,0);
        i++;
    }


}

void MainWindow::on_pushButton_clicked()
{
    if(isTimerStarted){
        isTimerStarted = false;
        ui->pushButton->setText("Start timer");

        th->exit();
        th->terminate();
    }
    else{
        isTimerStarted = true;
        ui->pushButton->setText("Stop timer");

        th->start();
        connect(th, &ThreadCalc::calculated, this, &MainWindow::addWidgetToGrid);

    }

}
