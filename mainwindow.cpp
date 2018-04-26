#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    int width = 200;
    int height = 200;

    ui->setupUi(this);
    tgs = new TGs(ui->graphicsView);

    tgs->str = "fkjklsdfjksdjf";
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setFrameStyle(0);
    ui->graphicsView->setScene(tgs);
    /*
    ui->graphicsView->setFixedSize(
                width+2 * ui->graphicsView->frameWidth(),
                height+2 * ui->graphicsView->frameWidth());

    ui->graphicsView->fitInView(0, 0, width, height, Qt::KeepAspectRatio);
*/
    //ui->graphicsView->setFixedSize(width, height);
    ui->graphicsView->setSceneRect(0, 0, width, height);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

MainWindow::~MainWindow()
{
    delete ui;
}
