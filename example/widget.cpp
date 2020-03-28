#include "widget.h"
#include "ui_widget.h"

#include <QAdvancedSpinBox/AdvancedSpinBox.h>
#include <QAdvancedSpinBox/AdvancedDoubleSpinBox.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
/*
    AdvancedDoubleSpinBox *doubleSpinBox = new AdvancedDoubleSpinBox(this);
    doubleSpinBox->setObjectName(QString::fromUtf8("advancedDoubleSpinBox"));
    doubleSpinBox->setGeometry(QRect(120, 40, 62, 22));
    doubleSpinBox->setDecimals(5);

    AdvancedSpinBox *spinBox = new AdvancedSpinBox(this);
    spinBox->setObjectName(QString::fromUtf8("advancedSpinBox"));
    spinBox->setGeometry(QRect(120, 80, 62, 22));
    */
}

Widget::~Widget()
{
    delete ui;
}

