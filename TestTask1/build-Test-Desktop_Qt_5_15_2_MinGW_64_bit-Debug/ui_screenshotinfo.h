/********************************************************************************
** Form generated from reading UI file 'screenshotinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENSHOTINFO_H
#define UI_SCREENSHOTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScreenshotInfo
{
public:
    QLabel *label;
    QLabel *Image;
    QLabel *percent;

    void setupUi(QWidget *ScreenshotInfo)
    {
        if (ScreenshotInfo->objectName().isEmpty())
            ScreenshotInfo->setObjectName(QString::fromUtf8("ScreenshotInfo"));
        ScreenshotInfo->resize(400, 100);
        label = new QLabel(ScreenshotInfo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 100, 30));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        Image = new QLabel(ScreenshotInfo);
        Image->setObjectName(QString::fromUtf8("Image"));
        Image->setGeometry(QRect(100, 0, 300, 100));
        QFont font1;
        font1.setPointSize(16);
        Image->setFont(font1);
        Image->setAlignment(Qt::AlignCenter);
        percent = new QLabel(ScreenshotInfo);
        percent->setObjectName(QString::fromUtf8("percent"));
        percent->setGeometry(QRect(0, 30, 100, 70));
        percent->setFont(font);
        percent->setAlignment(Qt::AlignCenter);

        retranslateUi(ScreenshotInfo);

        QMetaObject::connectSlotsByName(ScreenshotInfo);
    } // setupUi

    void retranslateUi(QWidget *ScreenshotInfo)
    {
        ScreenshotInfo->setWindowTitle(QCoreApplication::translate("ScreenshotInfo", "Form", nullptr));
        label->setText(QCoreApplication::translate("ScreenshotInfo", "Percent", nullptr));
        Image->setText(QCoreApplication::translate("ScreenshotInfo", "Image", nullptr));
        percent->setText(QCoreApplication::translate("ScreenshotInfo", "Percent", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScreenshotInfo: public Ui_ScreenshotInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENSHOTINFO_H
