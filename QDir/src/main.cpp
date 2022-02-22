#include <QCoreApplication>
#include <QDebug>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir directory;
    directory.setPath("C:/Users/Public/Desktop");
    qDebug() << directory[3];

    int total = directory.count();

    for (int n = 0; n < total; ++n) {
        qDebug() << directory[n];
    }

    qDebug() << directory.dirName();

    return a.exec();
}
