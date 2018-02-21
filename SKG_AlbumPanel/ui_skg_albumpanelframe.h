/********************************************************************************
** Form generated from reading UI file 'skg_albumpanelframe.ui'
**
** Created: Fri Jul 16 22:44:23 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKG_ALBUMPANELFRAME_H
#define UI_SKG_ALBUMPANELFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include "../SKG_AlbumWidget/skg_albumwidget.h"

QT_BEGIN_NAMESPACE

class Ui_SKG_AlbumPanelFrame
{
public:
    QGridLayout *gridLayout;
    SKG_AlbumWidget *AlbumWidget1;
    SKG_AlbumWidget *AlbumWidget2;
    SKG_AlbumWidget *AlbumWidget3;
    SKG_AlbumWidget *AlbumWidget4;

    void setupUi(QFrame *SKG_AlbumPanelFrame)
    {
        if (SKG_AlbumPanelFrame->objectName().isEmpty())
            SKG_AlbumPanelFrame->setObjectName(QString::fromUtf8("SKG_AlbumPanelFrame"));
        SKG_AlbumPanelFrame->resize(1024, 620);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SKG_AlbumPanelFrame->sizePolicy().hasHeightForWidth());
        SKG_AlbumPanelFrame->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(133, 131, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        SKG_AlbumPanelFrame->setPalette(palette);
        SKG_AlbumPanelFrame->setAutoFillBackground(true);
        SKG_AlbumPanelFrame->setFrameShape(QFrame::StyledPanel);
        SKG_AlbumPanelFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(SKG_AlbumPanelFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        AlbumWidget1 = new SKG_AlbumWidget(SKG_AlbumPanelFrame);
        AlbumWidget1->setObjectName(QString::fromUtf8("AlbumWidget1"));
        sizePolicy.setHeightForWidth(AlbumWidget1->sizePolicy().hasHeightForWidth());
        AlbumWidget1->setSizePolicy(sizePolicy);

        gridLayout->addWidget(AlbumWidget1, 0, 0, 1, 1);

        AlbumWidget2 = new SKG_AlbumWidget(SKG_AlbumPanelFrame);
        AlbumWidget2->setObjectName(QString::fromUtf8("AlbumWidget2"));
        sizePolicy.setHeightForWidth(AlbumWidget2->sizePolicy().hasHeightForWidth());
        AlbumWidget2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(AlbumWidget2, 0, 1, 1, 1);

        AlbumWidget3 = new SKG_AlbumWidget(SKG_AlbumPanelFrame);
        AlbumWidget3->setObjectName(QString::fromUtf8("AlbumWidget3"));
        sizePolicy.setHeightForWidth(AlbumWidget3->sizePolicy().hasHeightForWidth());
        AlbumWidget3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(AlbumWidget3, 1, 0, 1, 1);

        AlbumWidget4 = new SKG_AlbumWidget(SKG_AlbumPanelFrame);
        AlbumWidget4->setObjectName(QString::fromUtf8("AlbumWidget4"));
        sizePolicy.setHeightForWidth(AlbumWidget4->sizePolicy().hasHeightForWidth());
        AlbumWidget4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(AlbumWidget4, 1, 1, 1, 1);


        retranslateUi(SKG_AlbumPanelFrame);

        QMetaObject::connectSlotsByName(SKG_AlbumPanelFrame);
    } // setupUi

    void retranslateUi(QFrame *SKG_AlbumPanelFrame)
    {
        SKG_AlbumPanelFrame->setWindowTitle(QApplication::translate("SKG_AlbumPanelFrame", "Frame", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SKG_AlbumPanelFrame: public Ui_SKG_AlbumPanelFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKG_ALBUMPANELFRAME_H
