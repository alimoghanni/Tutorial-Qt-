#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnInfo_clicked()
{
    QMessageBox::information(this, "Information", "This is for Information");
}


void MainWindow::on_btnCritical_clicked()
{
    QMessageBox::critical(this, "Critical", "This is for Critical");
}


void MainWindow::on_btnWarning_clicked()
{
    QMessageBox::warning(this, "Warning", "This is for Warning");
}

