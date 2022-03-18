#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QMap>
#include <QDebug>
#include <ctime>

#define TOTAL 10000

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream io;
    QFile qfile;
    QMap<int, int>::Iterator it;
    QMap<int, int> qmap;
    int n, value, sum = 0;

    qsrand(time(NULL));
    qfile.setFileName("C:/Users/Public/Desktop/text.txt");
    qfile.open(QIODevice::WriteOnly | QIODevice::Text);
    io.setDevice(&qfile);

    for (int n = 0; n < TOTAL; ++n) {
        io << qrand() % 10 + 1 << ' ';
    }
    qfile.flush();
    qfile.close();

    qfile.open(QIODevice::ReadOnly | QIODevice::Text);

    while (!io.atEnd()) {
        io >> n;
        ++qmap[n];
    }

    qmap.erase(qmap.find(0));

    for (it = qmap.begin(); it != qmap.end(); ++it) {
        value = it.value();
        sum += value;
        qDebug() << it.key() << ":" << it.value();
    }

    qDebug() << "sum:" << sum;
    qDebug() << "Total:" << TOTAL;

    return a.exec();
}
