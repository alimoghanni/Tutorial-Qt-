#include <QCoreApplication>
#include <QVector>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> vecInt;
    vecInt << 1 << 2 << 7 << 9 << 5;

    qDebug() << vecInt;

    QVector<QString> vecQString;
    vecQString << "This" << "is" << "a" << "Vector" << "QString";

    qDebug() << vecQString;

    return a.exec();
}
