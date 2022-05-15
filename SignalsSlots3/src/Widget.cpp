#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->btnClose, &QPushButton::clicked, [&](){close();});
}

Widget::~Widget()
{
    delete ui;
}


