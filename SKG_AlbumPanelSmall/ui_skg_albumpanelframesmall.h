/********************************************************************************
** Form generated from reading UI file 'skg_albumpanelframesmall.ui'
**
** Created: Fri Jul 16 22:40:38 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKG_ALBUMPANELFRAMESMALL_H
#define UI_SKG_ALBUMPANELFRAMESMALL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include "../SKG_AlbumWidget/skg_albumwidget.h"

QT_BEGIN_NAMESPACE

class Ui_SKG_AlbumPanelFrameSmall
{
public:
    QHBoxLayout *horizontalLayout;
    SKG_AlbumWidget *AlbumWidget1;
    SKG_AlbumWidget *AlbumWidget2;

    void setupUi(QFrame *SKG_AlbumPanelFrameSmall)
    {
        if (SKG_AlbumPanelFrameSmall->objectName().isEmpty())
            SKG_AlbumPanelFrameSmall->setObjectName(QString::fromUtf8("SKG_AlbumPanelFrameSmall"));
        SKG_AlbumPanelFrameSmall->resize(1024, 400);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SKG_AlbumPanelFrameSmall->sizePolicy().hasHeightForWidth());
        SKG_AlbumPanelFrameSmall->setSizePolicy(sizePolicy);
        SKG_AlbumPanelFrameSmall->setMinimumSize(QSize(1024, 400));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(133, 131, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        SKG_AlbumPanelFrameSmall->setPalette(palette);
        SKG_AlbumPanelFrameSmall->setAutoFillBackground(true);
        SKG_AlbumPanelFrameSmall->setFrameShape(QFrame::NoFrame);
        SKG_AlbumPanelFrameSmall->setFrameShadow(QFrame::Plain);
        SKG_AlbumPanelFrameSmall->setLineWidth(1);
        SKG_AlbumPanelFrameSmall->setMidLineWidth(0);
        horizontalLayout = new QHBoxLayout(SKG_AlbumPanelFrameSmall);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        AlbumWidget1 = new SKG_AlbumWidget(SKG_AlbumPanelFrameSmall);
        AlbumWidget1->setObjectName(QString::fromUtf8("AlbumWidget1"));
        sizePolicy.setHeightForWidth(AlbumWidget1->sizePolicy().hasHeightForWidth());
        AlbumWidget1->setSizePolicy(sizePolicy);
        AlbumWidget1->setAutoFillBackground(true);
        AlbumWidget1->setFrameShape(QFrame::Box);
        AlbumWidget1->setFrameShadow(QFrame::Plain);

        horizontalLayout->addWidget(AlbumWidget1);

        AlbumWidget2 = new SKG_AlbumWidget(SKG_AlbumPanelFrameSmall);
        AlbumWidget2->setObjectName(QString::fromUtf8("AlbumWidget2"));
        sizePolicy.setHeightForWidth(AlbumWidget2->sizePolicy().hasHeightForWidth());
        AlbumWidget2->setSizePolicy(sizePolicy);
        AlbumWidget2->setAutoFillBackground(true);
        AlbumWidget2->setFrameShape(QFrame::Box);
        AlbumWidget2->setFrameShadow(QFrame::Plain);

        horizontalLayout->addWidget(AlbumWidget2);


        retranslateUi(SKG_AlbumPanelFrameSmall);

        QMetaObject::connectSlotsByName(SKG_AlbumPanelFrameSmall);
    } // setupUi

    void retranslateUi(QFrame *SKG_AlbumPanelFrameSmall)
    {
        SKG_AlbumPanelFrameSmall->setWindowTitle(QApplication::translate("SKG_AlbumPanelFrameSmall", "Frame", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SKG_AlbumPanelFrameSmall: public Ui_SKG_AlbumPanelFrameSmall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKG_ALBUMPANELFRAMESMALL_H
