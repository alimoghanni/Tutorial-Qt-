#include "Widget.h"
#include "ui_Widget.h"
#include "PersonDialog.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStringList titles;
    titles << "Name" << "Age" << "Salary";

    setWindowTitle("Employees");
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(titles);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnAdd_clicked()
{
    int result;
    QString name;
    int age;
    double salary;
    int row;
    PersonDialog pd(this);
    pd.setWindowTitle("Add an employee");
    result = pd.exec();
    if (result == QDialog::Rejected)
        return;
    name = pd.name();
    age = pd.age();
    salary = pd.salary();

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
	
    row = ui->tableWidget->rowCount() - 1;
	
    ui->tableWidget->setItem(row, NAME, new QTableWidgetItem(name));
    ui->tableWidget->setItem(row, AGE, new QTableWidgetItem(QString::number(age)));
    ui->tableWidget->setItem(row, SALARY, new QTableWidgetItem(QString::number(salary)));
}

