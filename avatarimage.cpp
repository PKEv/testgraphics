#include "avatarimage.h"

AvatarImage::AvatarImage(int h, int w, QWidget * parent) : QGraphicsView(parent)
{
    m_scene = new QGraphicsScene(0, 0, w, h, this);
    setScene(m_scene);

    size.setHeight(h);
    size.setWidth(w);

    resize(size);

    setSceneRect(0, 0, size.width(), size.height()); /* x, y, width, height */
    setRenderHint(QPainter::Antialiasing);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    QImage imageClose("d:/QtProjects/testgraphics/Close.svg");
    imageClose = imageClose.scaled(
                size.width() / 2,
                size.height() / 2,
                Qt::KeepAspectRatio,
                Qt::SmoothTransformation);
    QImage imageOpen("d:/QtProjects/testgraphics/Search.svg");
    imageOpen = imageOpen.scaled(
                size.width() / 2,
                size.height() / 2,
                Qt::KeepAspectRatio,
                Qt::SmoothTransformation);

    //QPixmap pixmap = setDefaultAvatar();

    itemAvatar = new QGraphicsPixmapItem();
    setDefaultAvatar();
    itemClose = new GraphicsPixmapItem(QPixmap::fromImage(imageClose));
    itemOpen = new GraphicsPixmapItem(QPixmap::fromImage(imageOpen));

    m_scene->addItem(itemAvatar);
    m_scene->addItem(itemClose);
    m_scene->addItem(itemOpen);

    itemClose->setPos(
                size.width() / 2,
                0);
    itemOpen->setPos(
                0,
                size.height() / 2);

    itemClose->setOpacity(opacity);
    itemOpen->setOpacity(opacity);

    connect(itemClose, SIGNAL(clicked()), this, SLOT(mousePressDropButton()) );
    connect(itemOpen, SIGNAL(clicked()), this, SLOT(mousePressOpenButton()) );
}

void AvatarImage::setDefaultAvatar()
{
    //QImage imgAvatar("d:/QtProjects/testgraphics2/myAvatar.png");
    QImage imgAvatar("d:/QtProjects/testgraphics/contact_dark.svg");
    setAvatar(imgAvatar);
}

void AvatarImage::mousePressOpenButton(void)
{
    emit openAvatar();
}

void AvatarImage::setAvatar(QImage imgAvatar)
{
    imgAvatar = imgAvatar.scaled(
                size.width() - 2,
                size.height() - 2,
                Qt::KeepAspectRatio,
                Qt::SmoothTransformation);
    QPixmap pixmap = getRoundedAvatar(imgAvatar);

    itemAvatar->setPixmap(pixmap);
}

void AvatarImage::mousePressDropButton()
{
    setDefaultAvatar();
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

