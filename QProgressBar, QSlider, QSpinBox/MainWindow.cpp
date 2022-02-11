#include "MainWindow.h"
#include <QProgressBar>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    m_progressBar(new QProgressBar(this)),
    m_layout(new QVBoxLayout(this)),
    m_hSlider(new QSlider(this)),
    m_spinBox(new QSpinBox(this))
{

    m_progressBar->setObjectName("progressBar");
    m_progressBar->setValue(10);

    m_hSlider->setObjectName("hSlider");
    m_hSlider->setOrientation(Qt::Horizontal);

    m_spinBox->setObjectName("spinBox");

    m_layout->addWidget(m_progressBar);
    m_layout->addWidget(m_hSlider);
    m_layout->addWidget(m_spinBox);

    connect(m_hSlider, &QSlider::valueChanged, m_progressBar, &QProgressBar::setValue);
    connect(m_hSlider, &QSlider::valueChanged, m_spinBox, &QSpinBox::setValue);

    connect(m_spinBox, QOverload<int>::of(&QSpinBox::valueChanged), m_progressBar, &QProgressBar::setValue);
    connect(m_spinBox, QOverload<int>::of(&QSpinBox::valueChanged), m_hSlider, &QSlider::setValue);

}
