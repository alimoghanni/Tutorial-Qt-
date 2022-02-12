#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QButtonGroup>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QButtonGroup *group = new QButtonGroup(this);
    group->setExclusive(true);
    group->addButton(ui->chBoxMarried);
    group->addButton(ui->chBoxDivorced);
    group->addButton(ui->chBoxSingle);
    group->addButton(ui->chBoxWidowed);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAccept_clicked()
{
    QString status;
    if (ui->chBoxMarried->isChecked())
        status = ui->chBoxMarried->text();

    if (ui->chBoxDivorced->isChecked())
        status = ui->chBoxDivorced->text();

    if (ui->chBoxSingle->isChecked())
        status = ui->chBoxSingle->text();

    if (ui->chBoxWidowed->isChecked())
        status = ui->chBoxWidowed->text();

    QMessageBox::information(this, "Your Marital status",status);

}

