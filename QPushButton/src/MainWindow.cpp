#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow),
    m_pushButton(new QPushButton(this))
{
    ui->setupUi(this);

    m_pushButton->setObjectName("Close Button");
    m_pushButton->setText(tr("Click me to close window"));
    m_pushButton->setMaximumWidth(200);
    m_pushButton->setGeometry(100,100,200,50);

    connect(m_pushButton, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

