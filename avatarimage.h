#ifndef AVATARIMAGE_H
#define AVATARIMAGE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>

#include "graphicspixmapitem.h"


class AvatarImage : public QGraphicsView
{
    Q_OBJECT
public:
    explicit AvatarImage(int h, int w, QWidget * parent = 0);


private:

    QPixmap getRoundedAvatar(QImage& img);

    QGraphicsScene *m_scene;

    GraphicsPixmapItem *item;
    GraphicsPixmapItem *item2;
    QGraphicsPixmapItem *item3;

};

#endif // AVATARIMAGE_H
