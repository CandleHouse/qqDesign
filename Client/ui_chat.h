/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QListWidget *listWidget_friends;
    QTextBrowser *textBrowser_record;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit_send;
    QPushButton *pushButton_send;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QListWidget *listWidget_sysInfo;

    void setupUi(QWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QStringLiteral("Chat"));
        Chat->resize(988, 546);
        horizontalLayout_3 = new QHBoxLayout(Chat);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(Chat);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        listWidget_friends = new QListWidget(Chat);
        listWidget_friends->setObjectName(QStringLiteral("listWidget_friends"));

        verticalLayout_2->addWidget(listWidget_friends);


        horizontalLayout_2->addLayout(verticalLayout_2);

        textBrowser_record = new QTextBrowser(Chat);
        textBrowser_record->setObjectName(QStringLiteral("textBrowser_record"));
        textBrowser_record->setMinimumSize(QSize(500, 420));

        horizontalLayout_2->addWidget(textBrowser_record);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        textEdit_send = new QTextEdit(Chat);
        textEdit_send->setObjectName(QStringLiteral("textEdit_send"));

        horizontalLayout->addWidget(textEdit_send);

        pushButton_send = new QPushButton(Chat);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setMinimumSize(QSize(50, 80));
        pushButton_send->setFont(font);

        horizontalLayout->addWidget(pushButton_send);


        verticalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(Chat);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        listWidget_sysInfo = new QListWidget(Chat);
        listWidget_sysInfo->setObjectName(QStringLiteral("listWidget_sysInfo"));
        listWidget_sysInfo->setMinimumSize(QSize(350, 0));

        verticalLayout->addWidget(listWidget_sysInfo);


        horizontalLayout_3->addLayout(verticalLayout);


        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QWidget *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Form", Q_NULLPTR));
        label_2->setText(QApplication::translate("Chat", "\345\234\250\347\272\277\345\245\275\345\217\213\345\210\227\350\241\250", Q_NULLPTR));
        textBrowser_record->setHtml(QApplication::translate("Chat", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        pushButton_send->setText(QApplication::translate("Chat", "\345\217\221\351\200\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("Chat", "\347\263\273\347\273\237\346\266\210\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
