#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databaseoperations.h"
#include "threadcalc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void loadWidgetsFromDB();

public slots:
    void addWidgetToGrid(class ScreenshotInfo* widget);

private slots:
    void on_pushButton_clicked();

private:

    Ui::MainWindow *ui;
    bool isTimerStarted = false;
    DataBaseOperations *db;
    ThreadCalc *th;
};
#endif // MAINWINDOW_H
