#ifndef THREADCALC_H
#define THREADCALC_H
#include "databaseoperations.h"

#include <QThread>
#include <QWidget>

class ThreadCalc: public QThread
{
    Q_OBJECT
public:
    ThreadCalc(class MainWindow *w_);


signals:
    void calculated(class ScreenshotInfo* widget);

private:
    void calculations();

private slots:
    void run();


private:
    class MainWindow *w;
    DataBaseOperations *db;
};

#endif // THREADCALC_H
