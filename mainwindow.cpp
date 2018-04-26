#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tgs = new TGs();

    tgs->str = "fkjklsdfjksdjf";
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setScene(tgs);
}

MainWindow::~MainWindow()
{
    delete ui;
}
