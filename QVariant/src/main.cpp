#include <QCoreApplication>
#include <QVariant>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVariant qv;
    qv.setValue<int>(5);

    qDebug() << qv;

    double dqv = qv.value<double>();
    qDebug() << "double:" << dqv;

    QList<QVariant> qlv;
    qlv << 20 << "twenty" << 22.1;
    qDebug() << qlv;


    return a.exec();
}
