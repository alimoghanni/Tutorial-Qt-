#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QSqlQueryModel;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pbtn_add_clicked();

    void on_pbtn_close_clicked();

    void on_pbtn_modify_clicked();

private:
    Ui::Widget *ui;
    QSqlDatabase m_database;
    QSqlQueryModel *m_model;
};
#endif // WIDGET_H
