#include "Widget.h"
#include "ui_Widget.h"
#include <QAction>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QAction *add;
    QAction *del;
    add = new QAction("add", this);
    del = new QAction("delete", this);

    connect(add, &QAction::triggered, this, &Widget::on_btnAdd_clicked);
    connect(del, &QAction::triggered, this, &Widget::on_btnDelete_clicked);

    ui->listWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
    ui->listWidget->addAction(add);
    ui->listWidget->addAction(del);
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


void Widget::on_btnDelete_clicked()
{
    delete ui->listWidget->currentItem();
}

