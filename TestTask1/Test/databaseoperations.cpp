#include "databaseoperations.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QImage>
#include <QVariant>


DataBaseOperations::DataBaseOperations(QString name)
{
    db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE", name));
    db->setDatabaseName("CompareImages.db");
    if (db->open()){
        QSqlQuery query(*db);
        query.exec("CREATE TABLE ScreenshotInfo(id INT PRIMARY KEY, hash vchar, percent REAL, file vchar)");   //if not exist create database. file is a path to the image
    }
    db->close();
}


void DataBaseOperations::insertData(QString hash, float percent, QString path){
    if (db->open()){
        QSqlQuery query(*db);
        query.exec("INSERT INTO ScreenshotInfo VALUES(" + QString::number(getCount()) + ", '" + hash + "', " + QString::number(percent) + " ,'" + path + "' );");
    }
    db->close();
}


QImage DataBaseOperations::getLastImage(){
    if (db->open()){
        QSqlQuery query(*db);
        int n =0;//= getCount()-1
        query.exec("SELECT file FROM ScreenshotInfo WHERE(id = " + QString::number(n) + ");");
        query.next();
        QString j = query.value(0).toString();
        return QImage(j);
    }
    db->close();
}

void DataBaseOperations::getDataAt(QImage& image, float& percent, int index){
    if (db->open()){
        QSqlQuery query(*db);
        query.exec("SELECT file, percent FROM ScreenshotInfo WHERE(id = " + QString::number(index) + ");");
        query.next();
        image = QImage(query.value(0).toString());
        percent = query.value(1).toFloat();
    }
    db->close();
}

int DataBaseOperations::getCount(){
    if (db->open()){
        QSqlQuery query(*db);
        //bool t = query.prepare("SELECT COUNT(id) FROM ScreenshotInfo");
        query.exec("SELECT COUNT(id) FROM ScreenshotInfo");

        query.next();
        return query.value(0).toInt();
    }
    db->close();
}
