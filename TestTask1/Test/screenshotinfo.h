#ifndef SCREENSHOTINFO_H
#define SCREENSHOTINFO_H

#include <QWidget>

namespace Ui {
class ScreenshotInfo;
}

class ScreenshotInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenshotInfo(QImage image, float percent, QWidget *parent = nullptr);
    ~ScreenshotInfo();

public:
    Ui::ScreenshotInfo *ui;
    class QPixmap *myPicture;
    float percent;
};

#endif // SCREENSHOTINFO_H
