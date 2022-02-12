#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QProgressBar;
class QVBoxLayout;
class QSlider;
class QSpinBox;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    QProgressBar *m_progressBar;
    QVBoxLayout *m_layout;
    QSlider *m_hSlider;
    QSpinBox *m_spinBox;

};
#endif // MAINWINDOW_H
