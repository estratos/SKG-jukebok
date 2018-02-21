/********************************************************************************
** Form generated from reading UI file 'skg_albumframe.ui'
**
** Created: Sat Oct 16 13:03:23 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKG_ALBUMFRAME_H
#define UI_SKG_ALBUMFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_SKG_AlbumFrame
{
public:
    QLabel *lblAlbumNumber;
    QListWidget *listTracks;
    QLabel *lblAlbumCover;
    QLabel *lblAlbumName;
    QLabel *lblArtistName;

    void setupUi(QFrame *SKG_AlbumFrame)
    {
        if (SKG_AlbumFrame->objectName().isEmpty())
            SKG_AlbumFrame->setObjectName(QString::fromUtf8("SKG_AlbumFrame"));
        SKG_AlbumFrame->setWindowModality(Qt::NonModal);
        SKG_AlbumFrame->resize(500, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SKG_AlbumFrame->sizePolicy().hasHeightForWidth());
        SKG_AlbumFrame->setSizePolicy(sizePolicy);
        SKG_AlbumFrame->setMinimumSize(QSize(0, 0));
        SKG_AlbumFrame->setSizeIncrement(QSize(1, 1));
        SKG_AlbumFrame->setBaseSize(QSize(500, 300));
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
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        QBrush brush2(QColor(133, 131, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        SKG_AlbumFrame->setPalette(palette);
        SKG_AlbumFrame->setAutoFillBackground(true);
        SKG_AlbumFrame->setFrameShape(QFrame::Box);
        SKG_AlbumFrame->setFrameShadow(QFrame::Plain);
        SKG_AlbumFrame->setLineWidth(1);
        lblAlbumNumber = new QLabel(SKG_AlbumFrame);
        lblAlbumNumber->setObjectName(QString::fromUtf8("lblAlbumNumber"));
        lblAlbumNumber->setGeometry(QRect(260, 10, 231, 22));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblAlbumNumber->sizePolicy().hasHeightForWidth());
        lblAlbumNumber->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("FreeSans"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        lblAlbumNumber->setFont(font);
        lblAlbumNumber->setAlignment(Qt::AlignCenter);
        listTracks = new QListWidget(SKG_AlbumFrame);
        listTracks->setObjectName(QString::fromUtf8("listTracks"));
        listTracks->setEnabled(false);
        listTracks->setGeometry(QRect(264, 36, 231, 251));
        sizePolicy.setHeightForWidth(listTracks->sizePolicy().hasHeightForWidth());
        listTracks->setSizePolicy(sizePolicy);
        listTracks->setMinimumSize(QSize(225, 0));
        listTracks->setBaseSize(QSize(225, 0));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        listTracks->setPalette(palette1);
        listTracks->setFrameShape(QFrame::NoFrame);
        listTracks->setFrameShadow(QFrame::Raised);
        lblAlbumCover = new QLabel(SKG_AlbumFrame);
        lblAlbumCover->setObjectName(QString::fromUtf8("lblAlbumCover"));
        lblAlbumCover->setGeometry(QRect(8, 8, 240, 240));
        sizePolicy.setHeightForWidth(lblAlbumCover->sizePolicy().hasHeightForWidth());
        lblAlbumCover->setSizePolicy(sizePolicy);
        lblAlbumCover->setFrameShape(QFrame::Box);
        lblAlbumCover->setScaledContents(true);
        lblAlbumName = new QLabel(SKG_AlbumFrame);
        lblAlbumName->setObjectName(QString::fromUtf8("lblAlbumName"));
        lblAlbumName->setGeometry(QRect(10, 280, 241, 16));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(18);
        sizePolicy2.setHeightForWidth(lblAlbumName->sizePolicy().hasHeightForWidth());
        lblAlbumName->setSizePolicy(sizePolicy2);
        lblAlbumName->setAlignment(Qt::AlignCenter);
        lblArtistName = new QLabel(SKG_AlbumFrame);
        lblArtistName->setObjectName(QString::fromUtf8("lblArtistName"));
        lblArtistName->setGeometry(QRect(10, 250, 241, 19));
        sizePolicy2.setHeightForWidth(lblArtistName->sizePolicy().hasHeightForWidth());
        lblArtistName->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bitstream Charter"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        lblArtistName->setFont(font1);
        lblArtistName->setFrameShape(QFrame::NoFrame);
        lblArtistName->setAlignment(Qt::AlignCenter);

        retranslateUi(SKG_AlbumFrame);

        QMetaObject::connectSlotsByName(SKG_AlbumFrame);
    } // setupUi

    void retranslateUi(QFrame *SKG_AlbumFrame)
    {
        SKG_AlbumFrame->setWindowTitle(QApplication::translate("SKG_AlbumFrame", "Frame", 0, QApplication::UnicodeUTF8));
        lblAlbumNumber->setText(QString());
        lblAlbumCover->setText(QString());
        lblAlbumName->setText(QString());
        lblArtistName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SKG_AlbumFrame: public Ui_SKG_AlbumFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKG_ALBUMFRAME_H
