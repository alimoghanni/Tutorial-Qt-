#include <QCoreApplication>
#include <QDataStream>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDataStream io;
    QFile qfFile;

    qfFile.setFileName("C:/Users/Public/Desktop/text.txt");
    qfFile.open(QIODevice::WriteOnly);
    io.setDevice(&qfFile);
    io << 20;

    qfFile.flush();
    qfFile.close();

    qDebug() << "some text...";

    return a.exec();
}
