#include "avatarimage.h"

AvatarImage::AvatarImage(int h, int w, QWidget * parent) : QGraphicsView(parent)
{
    m_scene = new QGraphicsScene(0, 0, w, h, this);
    setScene(m_scene);

    int size = 64;
    resize(size, size);

    setSceneRect(0, 0, size, size); /* x, y, width, height */
    setRenderHint(QPainter::Antialiasing);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    QImage image("d:/QtProjects/testgraphics2/Close.png");
    image = image.scaled(size / 3, size / 3, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QImage image2("d:/QtProjects/testgraphics2/Search.png");
    image2 = image2.scaled(size / 2, size / 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    QImage image3("d:/QtProjects/testgraphics2/myAvatar.png");
    image3 = image3.scaled(size - 2, size - 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap pixmap = getRoundedAvatar(image3);

    item3 = new QGraphicsPixmapItem(pixmap);
    item = new GraphicsPixmapItem(QPixmap::fromImage(image));
    item2 = new GraphicsPixmapItem(QPixmap::fromImage(image2));

    m_scene->addItem(item3);
    m_scene->addItem(item);
    m_scene->addItem(item2);

    item->setPos(size - size/5, 0);
    item2->setPos(size - size/4, size / 2);

    item->setOpacity(0.2);
    item2->setOpacity(0.2);
}

QPixmap AvatarImage::getRoundedAvatar(QImage& img)
{
    const QPixmap orig = QPixmap::fromImage(img);

    // getting size if the original picture is not square
    int size = qMax(orig.width(), orig.height());

    // creating a new transparent pixmap with equal sides
    QPixmap rounded = QPixmap(size, size);
    rounded.fill(Qt::transparent);

    // creating circle clip area
    QPainterPath path;
    path.addEllipse(rounded.rect());

    QPainter painter(&rounded);
    painter.setClipPath(path);

    // filling rounded area if needed
    painter.fillRect(rounded.rect(), Qt::black);

    // getting offsets if the original picture is not square
    int x = qAbs(orig.width() - size) / 2;
    int y = qAbs(orig.height() - size) / 2;
    painter.drawPixmap(x, y, orig.width(), orig.height(), orig);
    return rounded;
}

