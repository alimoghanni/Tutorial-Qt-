#include <QCoreApplication>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> qlist;
    qlist << 1 << 2 << 3 << 6 << 5 << 9;

    for (int n = 0; n < qlist.size(); ++n) {
        qDebug() << qlist[n];
    }

    qDebug() << "--------";

    foreach (int lst, qlist) {
        qDebug() << lst;
    }

    return a.exec();
}
