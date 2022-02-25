#include <QCoreApplication>
#include <QFileInfo>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFileInfo qfInfo;
    qfInfo.setFile("C:/Users/Public/Desktop/text.txt");

    qDebug() << qfInfo.fileName();
    qDebug() << qfInfo.filePath();
    qDebug() << qfInfo.size();

    qDebug() << qfInfo.exists();
    qDebug() << qfInfo.isExecutable();

    qDebug() << qfInfo.suffix();

    return a.exec();
}
