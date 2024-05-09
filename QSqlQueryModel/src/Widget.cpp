#include "Widget.h"
#include "ui_Widget.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    auto m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("c:/users/ali/desktop/data.db");

    if (!m_database.open()) {
        qDebug() << m_database.lastError().text();
        QMessageBox::critical(this, "Error", m_database.lastError().text());
        return;
    }

    QSqlQuery query;
    if(!query.exec("CREATE TABLE IF NOT EXISTS Person "
                   "(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
                   " name VARCHAR(255) NOT NULL, age INTERGER NOT NULL,"
                   " salary DOUBLE)"))
    {
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
        return;
    }

    /*
        Person("Alex", 15, 2000.0),
        Person("Jim", 22, 2400.0),
        Person("Kim", 45, 8000.0),
        Person("Jerry", 32, 1500.0),
        Person("Tom", 55, 7500.0)
    */



    m_model = new QSqlQueryModel(this);
    m_model->setQuery("SELECT * FROM Person");
    ui->tableView->setModel(m_model);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pbtn_add_clicked()
{
    QSqlQuery query;
    if (!query.exec(QString("INSERT INTO Person (name, age, salary)"
                            "VALUES ('%1', %2, %3)").
                    arg(ui->lineEdit_name->text()).
                    arg(ui->spinBox_age->value()).
                    arg(ui->doubleSpinBox_salary->value())))
    {
        QMessageBox::critical(this, "Error", query.lastError().text());
        return;
    }
    m_model->setQuery("SELECT * FROM Person");
}


void Widget::on_pbtn_close_clicked()
{
    close();
}


void Widget::on_pbtn_modify_clicked()
{
    auto loadInt = [&](QWidget *parent, const QString &title, const QString &msg, int value){
        bool ok;
        auto result = QInputDialog::getInt(parent, title, msg, value,
                     -2147483647, 2147483647, 1, &ok);

        if (ok) {
            return result;
        }
        return value;
    };

    auto loadName = [&](QWidget *parent, const QString &name){
        bool ok;
        auto result = QInputDialog::getText(parent, "Name", "Enter name",
                      QLineEdit::Normal, name, &ok);

        if (ok) {
            return result;
        }
        return name;
    };

    auto loadSalary = [&](QWidget *parent, double salary){
        bool ok;
        auto result = QInputDialog::getDouble(parent, "Salary", "Enter salary", salary,
                     -2147483647, 2147483647, 3, &ok);

        if (ok) {
            return result;
        }
        return salary;
    };




    int column = ui->tableView->currentIndex().column();
    int row = ui->tableView->currentIndex().row();
    QString sql;

    if (column == 0) {
        auto id = m_model->index(row, column).data().toInt();
        sql = QString("UPDATE Person SET id = %1 WHERE id = %2").
                arg(loadInt(this, "Id", "Enter id", id)).arg(id);
    } else if (column == 1) {
        auto name = m_model->index(row, column).data().toString();
        sql = QString("UPDATE Person SET name = '%1' WHERE name LIKE '%2'").
                arg(loadName(this, name)).arg(name);
    } else if (column == 2) {
        auto age = m_model->index(row, column).data().toInt();
        sql = QString("UPDATE Person SET age = %1 WHERE age = %2").
                arg(loadInt(this, "Age", "Enter age", age)).arg(age);
    } else if (column == 3) {
        auto salary = m_model->index(row, column).data().toDouble();
        sql = QString("UPDATE Person SET salary = %1 WHERE salary = %2").
                arg(loadSalary(this, salary)).arg(salary);
    }

    QSqlQuery query;
    query.exec(sql);
    m_model->setQuery("SELECT * FROM Person");
}

