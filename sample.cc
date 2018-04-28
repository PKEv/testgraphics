#include "sample.h"

#include <QtWidgets>
#include "avatarimage.h"

int main(int argc, char **argv)
{
  QApplication app(argc, argv);

  QWidget w;
  QHBoxLayout layout(&w);
  w.setMouseTracking(true);

  //QGraphicsScene scene;
  AvatarImage view1(64,644);
  //GraphicsView view1;

    layout.addWidget(&view1);

    view1.show();


  w.show();
  return app.exec();
}



