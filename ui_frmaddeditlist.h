/********************************************************************************
** Form generated from reading UI file 'frmaddeditlist.ui'
**
** Created: Tue Jul 19 22:09:10 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMADDEDITLIST_H
#define UI_FRMADDEDITLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTreeWidget>
#include "SKG_Button/skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_frmAddEditList
{
public:
    QFrame *frame;
    QTreeWidget *treeAvailableAlbums;
    QLabel *label_3;
    SKG_Button *btnAddAlbums;
    SKG_Button *btnRemoveAlbums;
    QTreeWidget *treeAlbumsInList;
    QLineEdit *txtName;
    QFrame *line;
    QLabel *label_2;
    QLabel *lblHeader;
    SKG_Button *btnSave;
    QLabel *label_4;
    SKG_Button *btnCancel;
    SKG_Button *btnKeyboard;

    void setupUi(QDialog *frmAddEditList)
    {
        if (frmAddEditList->objectName().isEmpty())
            frmAddEditList->setObjectName(QString::fromUtf8("frmAddEditList"));
        frmAddEditList->resize(800, 590);
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
        frmAddEditList->setPalette(palette);
        frame = new QFrame(frmAddEditList);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 791, 581));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        treeAvailableAlbums = new QTreeWidget(frame);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeAvailableAlbums->setHeaderItem(__qtreewidgetitem);
        treeAvailableAlbums->setObjectName(QString::fromUtf8("treeAvailableAlbums"));
        treeAvailableAlbums->setGeometry(QRect(10, 120, 321, 371));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        treeAvailableAlbums->setFont(font);
        treeAvailableAlbums->setFrameShape(QFrame::Box);
        treeAvailableAlbums->setFrameShadow(QFrame::Plain);
        treeAvailableAlbums->header()->setVisible(false);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 100, 301, 17));
        btnAddAlbums = new SKG_Button(frame);
        btnAddAlbums->setObjectName(QString::fromUtf8("btnAddAlbums"));
        btnAddAlbums->setGeometry(QRect(345, 180, 111, 71));
        btnAddAlbums->setAutoFillBackground(true);
        btnAddAlbums->setPixmap(QPixmap(QString::fromUtf8("resources/arrow-bold-right.jpg")));
        btnRemoveAlbums = new SKG_Button(frame);
        btnRemoveAlbums->setObjectName(QString::fromUtf8("btnRemoveAlbums"));
        btnRemoveAlbums->setGeometry(QRect(345, 270, 111, 71));
        btnRemoveAlbums->setAutoFillBackground(true);
        btnRemoveAlbums->setPixmap(QPixmap(QString::fromUtf8("resources/arrow-bold-left.jpg")));
        treeAlbumsInList = new QTreeWidget(frame);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("1"));
        treeAlbumsInList->setHeaderItem(__qtreewidgetitem1);
        treeAlbumsInList->setObjectName(QString::fromUtf8("treeAlbumsInList"));
        treeAlbumsInList->setGeometry(QRect(470, 120, 311, 371));
        treeAlbumsInList->setFont(font);
        treeAlbumsInList->setFrameShape(QFrame::Box);
        treeAlbumsInList->setFrameShadow(QFrame::Plain);
        treeAlbumsInList->header()->setVisible(false);
        txtName = new QLineEdit(frame);
        txtName->setObjectName(QString::fromUtf8("txtName"));
        txtName->setGeometry(QRect(10, 60, 301, 27));
        txtName->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white"));
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 32, 800, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 211, 17));
        lblHeader = new QLabel(frame);
        lblHeader->setObjectName(QString::fromUtf8("lblHeader"));
        lblHeader->setGeometry(QRect(0, 0, 800, 31));
        QPalette palette1;
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        lblHeader->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Digital-7"));
        font1.setPointSize(22);
        lblHeader->setFont(font1);
        lblHeader->setAlignment(Qt::AlignCenter);
        btnSave = new SKG_Button(frame);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(660, 500, 121, 71));
        btnSave->setAutoFillBackground(true);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(470, 100, 301, 17));
        btnCancel = new SKG_Button(frame);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(10, 500, 121, 71));
        btnCancel->setAutoFillBackground(true);
        btnKeyboard = new SKG_Button(frame);
        btnKeyboard->setObjectName(QString::fromUtf8("btnKeyboard"));
        btnKeyboard->setGeometry(QRect(330, 500, 141, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        btnKeyboard->setFont(font2);
        btnKeyboard->setAutoFillBackground(true);
        btnKeyboard->setWordWrap(true);

        retranslateUi(frmAddEditList);

        QMetaObject::connectSlotsByName(frmAddEditList);
    } // setupUi

    void retranslateUi(QDialog *frmAddEditList)
    {
        frmAddEditList->setWindowTitle(QApplication::translate("frmAddEditList", "Dialog", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("frmAddEditList", "Available Albums", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("frmAddEditList", "List Name", 0, QApplication::UnicodeUTF8));
        lblHeader->setText(QApplication::translate("frmAddEditList", "Add Custom List", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("frmAddEditList", "Save", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("frmAddEditList", "Albums in List", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("frmAddEditList", "Cancel", 0, QApplication::UnicodeUTF8));
        btnKeyboard->setText(QApplication::translate("frmAddEditList", "Onscreen Keyboard", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class frmAddEditList: public Ui_frmAddEditList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMADDEDITLIST_H
