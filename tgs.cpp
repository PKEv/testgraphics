#include <QtGui>
#include "tgs.h"
#define _alto  100
#define _ancho 100
#include <QGraphicsSceneMouseEvent>

TGs::TGs(QObject *parent)
    :QGraphicsScene(parent)
{ // Constructor of Scene
    this->over = false;

    QGraphicsTextItem * io = new QGraphicsTextItem;
    //int width = parent->width();
    //int heigth = this->height();
    //io->setPos(width / 2, heigth / 2);
    io->setPlainText("Barev");
/*
    QFont font;
    font.setPixelSize(500);
    font.setBold(false);
    font.setFamily("Calibri");

    io->setFont(font);
*/
    this->addItem(io);
}

void TGs::drawBackground(QPainter *painter, const QRectF &rect)
{

#define adjy 30
#define adjx 30

    int j = 0;
    int alto = 0;

    QPen pen;
    pen.setWidth(1);
    pen.setBrush(Qt::lightGray);
    painter->setPen(pen);

    painter->drawText(100, 100, this->str);
    /*
    alto = _alto;  // 50 + 2

    for(int i = 0; i < alto; ++i)
    {
        j = i * adjy - 17;

        painter->drawLine(QPoint(-210, j), QPoint(_ancho, j));
    }

    for(int i = 0; i < 300; ++i)
    {
        j = i * adjx - 210;

        painter->drawLine(QPoint(j, 0), QPoint(j, _ancho * 2));
    }*/
}

void TGs::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QString string = QString("%1, %2")
               .arg(mouseEvent->scenePos().x())
              .arg(mouseEvent->scenePos().y()); // Update the cursor position text
    this->str = string;
    this->update();
}

void TGs::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->update();
}

void TGs::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->update();
}
