/********************************************************************************
** Form generated from reading UI file 'pro_rec.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRO_REC_H
#define UI_PRO_REC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pro_Rec
{
public:
    QAction *actionReadFile;
    QAction *actionReadFile_2;
    QAction *actionset_Type;
    QAction *actionInitialize;
    QWidget *centralWidget;
    QLabel *show_img;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *gparameters;
    QPushButton *recgonization;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *radioButton_shape;
    QRadioButton *radioButton_chalky;
    QLabel *show_result;
    QWidget *widget;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *convert;
    QPushButton *denoising;
    QPushButton *splitback;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton;
    QPushButton *histogram;
    QMenuBar *menuBar;
    QMenu *start;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Pro_Rec)
    {
        if (Pro_Rec->objectName().isEmpty())
            Pro_Rec->setObjectName(QStringLiteral("Pro_Rec"));
        Pro_Rec->resize(719, 518);
        actionReadFile = new QAction(Pro_Rec);
        actionReadFile->setObjectName(QStringLiteral("actionReadFile"));
        actionReadFile_2 = new QAction(Pro_Rec);
        actionReadFile_2->setObjectName(QStringLiteral("actionReadFile_2"));
        actionset_Type = new QAction(Pro_Rec);
        actionset_Type->setObjectName(QStringLiteral("actionset_Type"));
        actionInitialize = new QAction(Pro_Rec);
        actionInitialize->setObjectName(QStringLiteral("actionInitialize"));
        centralWidget = new QWidget(Pro_Rec);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        show_img = new QLabel(centralWidget);
        show_img->setObjectName(QStringLiteral("show_img"));
        show_img->setGeometry(QRect(250, 10, 448, 448));
        show_img->setFrameShape(QFrame::Panel);
        show_img->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 240, 191, 31));
        QFont font;
        font.setFamily(QStringLiteral("UnDotum"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setLineWidth(3);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 380, 141, 31));
        label_5->setFont(font);
        label_5->setFrameShape(QFrame::NoFrame);
        label_5->setLineWidth(3);
        label_5->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 270, 161, 61));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gparameters = new QPushButton(layoutWidget);
        gparameters->setObjectName(QStringLiteral("gparameters"));

        verticalLayout_2->addWidget(gparameters);

        recgonization = new QPushButton(layoutWidget);
        recgonization->setObjectName(QStringLiteral("recgonization"));

        verticalLayout_2->addWidget(recgonization);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(80, 410, 114, 54));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        radioButton_shape = new QRadioButton(layoutWidget1);
        radioButton_shape->setObjectName(QStringLiteral("radioButton_shape"));

        verticalLayout_4->addWidget(radioButton_shape);

        radioButton_chalky = new QRadioButton(layoutWidget1);
        radioButton_chalky->setObjectName(QStringLiteral("radioButton_chalky"));

        verticalLayout_4->addWidget(radioButton_chalky);

        show_result = new QLabel(centralWidget);
        show_result->setObjectName(QStringLiteral("show_result"));
        show_result->setGeometry(QRect(10, 340, 231, 41));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        show_result->setFont(font1);
        show_result->setFrameShape(QFrame::Panel);
        show_result->setFrameShadow(QFrame::Raised);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 10, 191, 221));
        verticalLayout_8 = new QVBoxLayout(widget);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setFrameShape(QFrame::NoFrame);
        label->setLineWidth(3);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        convert = new QPushButton(widget);
        convert->setObjectName(QStringLiteral("convert"));

        verticalLayout->addWidget(convert);

        denoising = new QPushButton(widget);
        denoising->setObjectName(QStringLiteral("denoising"));

        verticalLayout->addWidget(denoising);

        splitback = new QPushButton(widget);
        splitback->setObjectName(QStringLiteral("splitback"));

        verticalLayout->addWidget(splitback);


        verticalLayout_3->addLayout(verticalLayout);


        verticalLayout_7->addLayout(verticalLayout_3);


        verticalLayout_8->addLayout(verticalLayout_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetNoConstraint);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setLayoutDirection(Qt::RightToLeft);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_3);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_5->addWidget(pushButton);

        histogram = new QPushButton(widget);
        histogram->setObjectName(QStringLiteral("histogram"));

        verticalLayout_5->addWidget(histogram);


        horizontalLayout_2->addLayout(verticalLayout_5);


        verticalLayout_8->addLayout(horizontalLayout_2);

        Pro_Rec->setCentralWidget(centralWidget);
        layoutWidget->raise();
        show_img->raise();
        layoutWidget->raise();
        label_4->raise();
        layoutWidget->raise();
        label_5->raise();
        histogram->raise();
        pushButton->raise();
        label_2->raise();
        label_2->raise();
        show_result->raise();
        menuBar = new QMenuBar(Pro_Rec);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 719, 28));
        start = new QMenu(menuBar);
        start->setObjectName(QStringLiteral("start"));
        Pro_Rec->setMenuBar(menuBar);
        statusBar = new QStatusBar(Pro_Rec);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Pro_Rec->setStatusBar(statusBar);

        menuBar->addAction(start->menuAction());
        start->addAction(actionReadFile_2);
        start->addAction(actionInitialize);

        retranslateUi(Pro_Rec);

        QMetaObject::connectSlotsByName(Pro_Rec);
    } // setupUi

    void retranslateUi(QMainWindow *Pro_Rec)
    {
        Pro_Rec->setWindowTitle(QApplication::translate("Pro_Rec", "Pro_Rec", Q_NULLPTR));
        actionReadFile->setText(QApplication::translate("Pro_Rec", "ReadFile", Q_NULLPTR));
        actionReadFile_2->setText(QApplication::translate("Pro_Rec", "ReadFile", Q_NULLPTR));
        actionset_Type->setText(QApplication::translate("Pro_Rec", "set_Type", Q_NULLPTR));
        actionInitialize->setText(QApplication::translate("Pro_Rec", "Initialize", Q_NULLPTR));
        show_img->setText(QString());
        label_4->setText(QApplication::translate("Pro_Rec", "Recgonazition_IMG", Q_NULLPTR));
        label_5->setText(QApplication::translate("Pro_Rec", "Type", Q_NULLPTR));
        gparameters->setText(QApplication::translate("Pro_Rec", "Get_Parameters", Q_NULLPTR));
        recgonization->setText(QApplication::translate("Pro_Rec", "Recgonization", Q_NULLPTR));
        radioButton_shape->setText(QApplication::translate("Pro_Rec", "Shape", Q_NULLPTR));
        radioButton_chalky->setText(QApplication::translate("Pro_Rec", "Chalky", Q_NULLPTR));
        show_result->setText(QString());
        label->setText(QApplication::translate("Pro_Rec", "Process_IMG", Q_NULLPTR));
        convert->setText(QApplication::translate("Pro_Rec", "Convert_IMG", Q_NULLPTR));
        denoising->setText(QApplication::translate("Pro_Rec", "Denoising", Q_NULLPTR));
        splitback->setText(QApplication::translate("Pro_Rec", "Split_Back", Q_NULLPTR));
        label_2->setText(QApplication::translate("Pro_Rec", "(shape)", Q_NULLPTR));
        label_3->setText(QApplication::translate("Pro_Rec", "(Chalky)", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Pro_Rec", "Boundary", Q_NULLPTR));
        histogram->setText(QApplication::translate("Pro_Rec", "Histogram", Q_NULLPTR));
        start->setTitle(QApplication::translate("Pro_Rec", "Start", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Pro_Rec: public Ui_Pro_Rec {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRO_REC_H
