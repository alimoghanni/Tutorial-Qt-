#include <QCoreApplication>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray content;
    QFile qFile;
    qFile.setFileName("C:/Users/Public/Desktop/text.txt");

    if (!qFile.exists())
    {
        qDebug() << "The file does not exists!";
        return 1;
    }

    qFile.open(QIODevice::ReadOnly | QIODevice::Text);

    if (!qFile.isOpen())
    {
        qDebug() << "The file does not open!";
        return 2;
    }

    content = qFile.readAll();
    qDebug() << content;

    //content = "I am writing to file";
    //qFile.open(QIODevice::WriteOnly | QIODevice::Text);
    //qFile.write(content);
    //qFile.flush();
    //qFile.close();


    return a.exec();
}
