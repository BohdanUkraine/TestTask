#include "threadcalc.h"
#include "mainwindow.h"
#include <QScreen>
#include <QPixmap>
#include <QImage>
#include <QCryptographicHash>
#include "screenshotinfo.h"
#include <QThread>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

ThreadCalc::ThreadCalc(MainWindow *w_):
        QThread(w_)
{
    w = w_;
    db = new DataBaseOperations("thread2");
}



void ThreadCalc::run(){
    //

    while(this->isRunning()){
        calculations();
        qDebug("asa\n");
        this->msleep(60000);
    }

}

void ThreadCalc::calculations(){
    if(db->getCount() > 0){
        QImage img1 = db->getLastImage();

        auto geom = w->screen()->geometry();
        QPixmap qpx_pixmap = w->screen()->grabWindow(0, geom.x(), geom.y(), geom.width(), geom.height());
        QImage img = qpx_pixmap.toImage();

        int count = 0;
        for(int i=0; i<geom.width(); i++)
            for(int j=0; j<geom.height(); j++)
                if(img1.pixel(QPoint(i,j)) != img.pixel(QPoint(i,j)))
                    count++;

        float percent = 100 - (float(count) / (geom.width()*geom.height()) * 100);


        QString fileName = "imgs/"+QString::number(db->getCount())+".png"; //filename
        img.save(fileName);
        QCryptographicHash *data = new QCryptographicHash(QCryptographicHash::Md5);
        data->addData(QString::number(img.cacheKey()).toUtf8());
        db->insertData(data->result(), percent, fileName);

        ScreenshotInfo *info = new ScreenshotInfo(img, percent);
        emit calculated(info);
    }
}

