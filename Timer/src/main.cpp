#include <QCoreApplication>
#include <QTime>
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    if (argc == 1) {
        qDebug() << QString("Use '%1' program.exe result.txt").arg(argv[0]);
        return 1;
    }

    int res;
    QTime start;
    QFile archive;
    QTextStream io;
    QProcess proc;
    QString program = argv[1];
    QString result = argv[2];

    QCoreApplication a(argc, argv);

    start = QTime::currentTime();
    proc.start(program);
    proc.waitForFinished();
    res = start.msecsTo(QTime::currentTime());
    archive.setFileName(result);
    archive.open(QIODevice::WriteOnly | QIODevice::Text);
    io.setDevice(&archive);
    io << "Program: " << program << " took " << res << " miliseconds";

    archive.flush();
    archive.close();

    qDebug() << "Ready ....... Press Ctrl+C to finish";


    return a.exec();
}
