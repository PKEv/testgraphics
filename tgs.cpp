#include <QtGui>
#include "tgs.h"
#define _alto  100
#define _ancho 100
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsOpacityEffect>
#include <QStyleOptionGraphicsItem>


class myItem2 : public QGraphicsPixmapItem
{
public:
myItem2(QGraphicsPixmapItem *parent = 0) : QGraphicsPixmapItem(parent)
{
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemSendsScenePositionChanges | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);
    setAcceptHoverEvents(true);
}
/*
void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0)
{
    painter->setBrush(QColor(230,230,230));
    if (option->state.testFlag(QStyle::State_MouseOver))
        painter->setBrush(QColor(0,230,230));
    painter->drawRect(option->rect);
    QGraphicsPixmapItem::paint(painter, option, widget);
}
*/
void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override
{
    setOffset(10,10);
}
};


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
    //QImage image = QImage()

    //QGraphicsPixmapItem *it1 = new QGraphicsPixmapItem(QPixmap("d:\QtProjects\testgraphics\Very-Basic-Search-icon.png"));
    //this->addPixmap(QPixmap("d:\QtProjects\testgraphics\Very-Basic-Search-icon.png"));

    QString url1 = R"(d:\QtProjects\testgraphics\Search.png)";
    QString url2 = R"(d:\QtProjects\testgraphics\Close.png)";

    QPixmap img1(url1);
    QPixmap img2(url2);

    //this->addPixmap(img);
    img1 = img1.scaled(100, 100, Qt::KeepAspectRatio);
    img2 = img2.scaled(100, 100, Qt::KeepAspectRatio);

    myItem2 *it1;// = new myItem2(img1);
    it2 = new QGraphicsPixmapItem(img2);
    it2->setOffset(0, 100);

    it1 = new myItem2();
    it1->setPixmap(img1);


    this->addItem(it1);
    this->addItem(it2);


    it1->setVisible(true);
    //it1->setVisible(false);
    it2->setVisible(true);

    //connect(it, SIGNAL())

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

    painter->drawText(0, 0, this->str);
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
    //it1->setVisible(true);
    it2->setVisible(true);
    /*

    QGraphicsOpacityEffect *opacity = new QGraphicsOpacityEffect;
        QPropertyAnimation *anim = new QPropertyAnimation( opacity, "opacity" );
        it1->setGraphicsEffect(opacity);

        anim->setDuration( 500 );
            anim->setStartValue( 1.0 );
            anim->setEndValue( 0.0 );
            anim->setEasingCurve( QEasingCurve::InCubic );
            anim->start();
*/

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
