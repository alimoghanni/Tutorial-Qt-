#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDate date(2022,02,01);
    QTime time(10,42,11);
    QDateTime dt(date,time);

    qDebug() << dt;

    qDebug() << QDateTime::currentDateTime();
    qDebug() << QDate::currentDate();
    qDebug() << QTime::currentTime();

    QDateTime startDate(QDate(2012, 7, 6), QTime(8, 30, 0));
    QDateTime endDate(QDate(2012, 7, 10), QTime(16, 30, 0));
    qDebug() << "Days from startDate to endDate: " << startDate.daysTo(endDate);

    startDate = QDateTime(QDate(2012, 7, 6), QTime(23, 55, 0));
    endDate = QDateTime(QDate(2012, 7, 10), QTime(0, 5, 0));
    qDebug() << "Days from startDate to endDate: " << startDate.daysTo(endDate);

    qSwap(startDate, endDate); // Make endDate before startDate.
    qDebug() << "Days from startDate to endDate: " << startDate.daysTo(endDate);

    return a.exec();
}
