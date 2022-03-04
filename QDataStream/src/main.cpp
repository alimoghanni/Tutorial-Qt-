#include <QCoreApplication>
#include <QDataStream>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDataStream io;
    QFile qfFile;

    qfFile.setFileName("E:/Apps/Alfatraining_C++_Qt/Tutorial Qt Creator/Tutorial Qt Creator - QDataStream/QDataStream/text.txt");
    qfFile.open(QIODevice::WriteOnly);
    io.setDevice(&qfFile);
    io << 20;

    qfFile.flush();
    qfFile.close();

    qDebug() << "some text...";


    return a.exec();
}
