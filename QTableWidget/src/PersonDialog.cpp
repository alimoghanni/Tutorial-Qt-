#include "PersonDialog.h"
#include "ui_PersonDialog.h"

PersonDialog::PersonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonDialog)
{
    ui->setupUi(this);
}

PersonDialog::~PersonDialog()
{
    delete ui;
}

void PersonDialog::on_buttonBox_accepted()
{
    accept();
}


void PersonDialog::on_buttonBox_rejected()
{
    reject();
}

QString PersonDialog::name() const
{
    return ui->lineEditName->text();
}

int PersonDialog::age() const
{
    return ui->spinBoxAge->value();
}

double PersonDialog::salary() const
{
    return ui->doubleSpinBoxSalary->value();
}



