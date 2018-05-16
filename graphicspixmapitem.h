#ifndef GRAPHICSPIXMAPITEM_H
#define GRAPHICSPIXMAPITEM_H


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
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

class GraphicsPixmapItem : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
  //enum ClickQuadrant { None=0, TopLeft, TopRight, BotLeft, BotRight };

  GraphicsPixmapItem(const QPixmap & pixmap, QGraphicsItem * parent = 0);
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
  QRectF boundingRect() const override;
signals:
  void clicked();
protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
  void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;
  void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
  void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
private:
  QRectF m_imageRect;
  //QRectF m_newRect;
  QPixmap m_pixmap;
  //QPointF m_clickPosition;
  //ClickQuadrant m_quad = ClickQuadrant::None;
};


#endif // GRAPHICSPIXMAPITEM_H
