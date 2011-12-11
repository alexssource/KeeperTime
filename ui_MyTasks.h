/********************************************************************************
** Form generated from reading UI file 'MyTasks.ui'
**
** Created: Sat Dec 10 08:20:15 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTASKS_H
#define UI_MYTASKS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyTasks
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QLabel *labelMyTasks;
    QLabel *labelDate;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MyTasks)
    {
        if (MyTasks->objectName().isEmpty())
            MyTasks->setObjectName(QString::fromUtf8("MyTasks"));
        MyTasks->resize(704, 424);
        centralwidget = new QWidget(MyTasks);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QFont font;
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferAntialias);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QFont font1;
        font1.setStyleStrategy(QFont::PreferDefault);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem6->setFont(font1);
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(0, 5, __qtablewidgetitem12);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 40, 671, 351));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(671, 0));
        tableWidget->setMouseTracking(true);
        tableWidget->setAcceptDrops(false);
        tableWidget->setAutoFillBackground(false);
        tableWidget->setStyleSheet(QString::fromUtf8("padding: 0 3px;"));
        tableWidget->setFrameShape(QFrame::StyledPanel);
        tableWidget->setFrameShadow(QFrame::Sunken);
        tableWidget->setAutoScroll(true);
        tableWidget->setAutoScrollMargin(10);
        tableWidget->setDragEnabled(true);
        tableWidget->setDragDropMode(QAbstractItemView::NoDragDrop);
        tableWidget->setGridStyle(Qt::DashDotLine);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget->horizontalHeader()->setMinimumSectionSize(24);
        labelMyTasks = new QLabel(centralwidget);
        labelMyTasks->setObjectName(QString::fromUtf8("labelMyTasks"));
        labelMyTasks->setGeometry(QRect(20, 10, 201, 21));
        labelDate = new QLabel(centralwidget);
        labelDate->setObjectName(QString::fromUtf8("labelDate"));
        labelDate->setGeometry(QRect(570, 0, 121, 20));
        MyTasks->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MyTasks);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 704, 21));
        MyTasks->setMenuBar(menubar);
        statusbar = new QStatusBar(MyTasks);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MyTasks->setStatusBar(statusbar);

        retranslateUi(MyTasks);

        QMetaObject::connectSlotsByName(MyTasks);
    } // setupUi

    void retranslateUi(QMainWindow *MyTasks)
    {
        MyTasks->setWindowTitle(QApplication::translate("MyTasks", "MyTasks", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MyTasks", "Id", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MyTasks", "\320\227\320\260\320\264\320\260\321\207\320\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MyTasks", "\320\241\321\202\320\260\321\202\321\203\321\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MyTasks", "\320\227\320\260\321\202\321\200\320\260\321\207\320\265\320\275\320\275\320\276\320\265 \320\262\321\200\320\265\320\274\321\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MyTasks", "\320\237\320\273\320\260\320\275\320\270\321\200\321\203\320\265\320\274\320\276\320\265 \320\262\321\200\320\265\320\274\321\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MyTasks", "\320\237\321\200\320\270\320\276\321\200\320\270\321\202\320\265\321\202", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MyTasks", "1", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 0);
        ___qtablewidgetitem7->setText(QApplication::translate("MyTasks", "7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 1);
        ___qtablewidgetitem8->setText(QApplication::translate("MyTasks", "\320\240\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\260\321\202\321\214 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\264\320\273\321\217 IPhone", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 2);
        ___qtablewidgetitem9->setText(QApplication::translate("MyTasks", "\320\222\321\213\320\277\320\276\320\273\320\275\321\217\321\202\320\265\321\201\321\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(0, 3);
        ___qtablewidgetitem10->setText(QApplication::translate("MyTasks", "6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 4);
        ___qtablewidgetitem11->setText(QApplication::translate("MyTasks", "10", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(0, 5);
        ___qtablewidgetitem12->setText(QApplication::translate("MyTasks", "7", 0, QApplication::UnicodeUTF8));
        tableWidget->setSortingEnabled(__sortingEnabled);

        labelMyTasks->setText(QApplication::translate("MyTasks", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600;\">\320\234\320\276\320\270 \321\202\320\265\320\272\321\203\321\211\320\270\320\265 \320\267\320\260\320\264\320\260\321\207\320\270:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        labelDate->setText(QApplication::translate("MyTasks", "17 November 2011", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyTasks: public Ui_MyTasks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTASKS_H
