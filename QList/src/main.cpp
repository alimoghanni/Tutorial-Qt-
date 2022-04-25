#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int sum1 = 0;
    int sum2 = 0;

    QList<int> list, list2;
    list.append(1);
    list.append(2);
    list.append(3);

    list << 4 << 5 << 6 << 3  << 3 << 7;

    list2 = list;

    qDebug() << list;

    QList<int>::Iterator i;
    for (i = list.begin(); i != list.end(); ++i) {
        sum1 += *i;
    }

    qDebug() << "sum from iterator: " << sum1;

    for (int n = 0; n < list.size(); ++n) {
        sum2 += list.at(n);  // sum2 += list[n];
    }

    qDebug() << "sum from for loop: " << sum2;

    list.removeFirst();
    qDebug() << "Remove first element: " << list;

    list.removeLast();
    qDebug() << "Remove last element: " << list;

    list.removeAt(2);
    qDebug() << "Remove index 2 element: " << list;

    list.removeOne(3);
    qDebug() << "Remove element (3): " << list;

    list.removeAll(3);
    qDebug() << "Remove All (3) 's:" << list;

    list.clear();
    qDebug() << "Remove All elements:" << list;

    qDebug();

    foreach (int i, list2) {
        qDebug() << i;
    }

    QList<QString> qslist;
    qslist << "This" << "is" << "a" << "list.";
    qDebug() << qslist;

    QStringList qstringlist;
    qstringlist << "This" << "is" << "a" << "qstring" << "list.";
    qDebug() << qstringlist;

    QString qstr = "Enjoy, learning, C++";
    QStringList newlist = qstr.split(',');
    qDebug() << newlist;

    QString qstrjoin = newlist.join('-');
    qDebug() << qstrjoin;


    return a.exec();
}
