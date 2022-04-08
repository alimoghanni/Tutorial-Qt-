#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QInputDialog>


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("XXXX");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    double n = QInputDialog::getDouble(this, "Enter", "Input a value:", 0.00, -2147483647, 2147483647, 2);
    ui->label->setText(QString::number(n));
}

