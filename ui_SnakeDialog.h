/********************************************************************************
** Form generated from reading UI file 'SnakeDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAKEDIALOG_H
#define UI_SNAKEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SnakeDialog
{
public:
    QFrame *frame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *scorelabel;
    QLabel *label_4;
    QLabel *speedlabel;
    QLabel *label_2;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *exitButton;

    void setupUi(QDialog *SnakeDialog)
    {
        if (SnakeDialog->objectName().isEmpty())
            SnakeDialog->setObjectName(QStringLiteral("SnakeDialog"));
        SnakeDialog->resize(702, 405);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        SnakeDialog->setFont(font);
        SnakeDialog->setAutoFillBackground(true);
        frame = new QFrame(SnakeDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 580, 380));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(5);
        frame->setMidLineWidth(0);
        layoutWidget = new QWidget(SnakeDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(600, 10, 86, 381));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        scorelabel = new QLabel(layoutWidget);
        scorelabel->setObjectName(QStringLiteral("scorelabel"));
        scorelabel->setFrameShape(QFrame::WinPanel);
        scorelabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(scorelabel);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        speedlabel = new QLabel(layoutWidget);
        speedlabel->setObjectName(QStringLiteral("speedlabel"));
        speedlabel->setFrameShape(QFrame::WinPanel);
        speedlabel->setTextFormat(Qt::AutoText);
        speedlabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(speedlabel);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        startButton = new QPushButton(layoutWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setFont(font);
        startButton->setFocusPolicy(Qt::ClickFocus);
        startButton->setAutoDefault(true);

        verticalLayout->addWidget(startButton);

        pauseButton = new QPushButton(layoutWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setEnabled(false);
        pauseButton->setFont(font);
        pauseButton->setFocusPolicy(Qt::ClickFocus);
        pauseButton->setAutoDefault(true);

        verticalLayout->addWidget(pauseButton);

        exitButton = new QPushButton(layoutWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setEnabled(false);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        font1.setItalic(false);
        exitButton->setFont(font1);
        exitButton->setFocusPolicy(Qt::ClickFocus);
        exitButton->setAutoDefault(true);

        verticalLayout->addWidget(exitButton);


        retranslateUi(SnakeDialog);

        QMetaObject::connectSlotsByName(SnakeDialog);
    } // setupUi

    void retranslateUi(QDialog *SnakeDialog)
    {
        SnakeDialog->setWindowTitle(QApplication::translate("SnakeDialog", "SnakeDialog", 0));
        label->setText(QApplication::translate("SnakeDialog", "\346\202\250\347\232\204\345\210\206\346\225\260", 0));
        scorelabel->setText(QApplication::translate("SnakeDialog", "0", 0));
        label_4->setText(QApplication::translate("SnakeDialog", "\345\275\223\345\211\215\351\200\237\345\272\246", 0));
        speedlabel->setText(QApplication::translate("SnakeDialog", "2", 0));
        label_2->setText(QApplication::translate("SnakeDialog", "Ctrl/Shift", 0));
        startButton->setText(QApplication::translate("SnakeDialog", "\345\274\200\345\247\213\346\270\270\346\210\217", 0));
        pauseButton->setText(QApplication::translate("SnakeDialog", "\346\232\202\345\201\234\346\270\270\346\210\217", 0));
        exitButton->setText(QApplication::translate("SnakeDialog", "\347\273\210\346\255\242\346\270\270\346\210\217", 0));
    } // retranslateUi

};

namespace Ui {
    class SnakeDialog: public Ui_SnakeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAKEDIALOG_H
