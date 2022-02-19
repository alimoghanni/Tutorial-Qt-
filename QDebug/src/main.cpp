#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Hello Qt!";
    qDebug() << 20;
    qDebug("Good Bye!");

    return a.exec();
}
