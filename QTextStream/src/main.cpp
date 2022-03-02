#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream io;
    QFile qfFile;
    QString content;

    qfFile.setFileName("C:/Users/Public/Desktop/text.txt");
    qfFile.open(QIODevice::ReadWrite | QIODevice::Text);

    if (!qfFile.isOpen()) {
        qDebug() << "Error: file is not open!";
        return 1;
    }

    io.setDevice(&qfFile);
    //io << "Text are inserted.";

    content = io.readAll();
    qDebug() << content;

    qfFile.flush();
    qfFile.close();




    return a.exec();
}
