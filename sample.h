#ifndef _SAMPLE_H_
#define _SAMPLE_H_

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QGridLayout>
#include <QObject>
#include <QPainter>
#include <QPointF>
#include <QSlider>
#include <QTransform>

class GraphicsView : public QGraphicsView
{
public:
    GraphicsView(QWidget * parent = 0);

    QGraphicsScene *scene;

};




#endif // SAMPLE_H
