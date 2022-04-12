#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnAdd_clicked()
{
    QString name;
    name = ui->lineEdit->text();
    if (name.isEmpty())
        return;
    ui->listWidget->addItem(name);
}


void Widget::on_pushButton_2_clicked()
{
    delete ui->listWidget->currentItem();
}

