/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_port;
    QPushButton *pushButton_listen;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QTableView *tableView_online;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_content;
    QPushButton *pushButton_find;
    QListWidget *listWidget_log;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(844, 563);
        horizontalLayout_3 = new QHBoxLayout(Widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_port = new QLineEdit(Widget);
        lineEdit_port->setObjectName(QStringLiteral("lineEdit_port"));

        horizontalLayout->addWidget(lineEdit_port);

        pushButton_listen = new QPushButton(Widget);
        pushButton_listen->setObjectName(QStringLiteral("pushButton_listen"));

        horizontalLayout->addWidget(pushButton_listen);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        tableView_online = new QTableView(Widget);
        tableView_online->setObjectName(QStringLiteral("tableView_online"));
        tableView_online->setTextElideMode(Qt::ElideLeft);
        tableView_online->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(tableView_online);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit_content = new QLineEdit(Widget);
        lineEdit_content->setObjectName(QStringLiteral("lineEdit_content"));

        horizontalLayout_2->addWidget(lineEdit_content);

        pushButton_find = new QPushButton(Widget);
        pushButton_find->setObjectName(QStringLiteral("pushButton_find"));

        horizontalLayout_2->addWidget(pushButton_find);


        verticalLayout_3->addLayout(horizontalLayout_2);

        listWidget_log = new QListWidget(Widget);
        listWidget_log->setObjectName(QStringLiteral("listWidget_log"));

        verticalLayout_3->addWidget(listWidget_log);


        horizontalLayout_3->addLayout(verticalLayout_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\346\234\215\345\212\241\347\233\221\346\216\247\345\217\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        lineEdit_port->setText(QApplication::translate("Widget", "8080", Q_NULLPTR));
        pushButton_listen->setText(QApplication::translate("Widget", "\345\274\200\345\247\213\347\233\221\345\220\254", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "\345\234\250\347\272\277\345\210\227\350\241\250", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "\346\227\245\345\277\227", Q_NULLPTR));
        pushButton_find->setText(QApplication::translate("Widget", "\346\237\245\350\257\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
