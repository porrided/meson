#include <QApplication>
#include "mainWindow.h"

#if QT_VERSION > 0x050000
// include some random private headers
    #include <private/qobject_p.h>
#endif

int main(int argc, char **argv) {
  #ifndef UNITY_BUILD
  Q_INIT_RESOURCE(stuff);
  Q_INIT_RESOURCE(stuff2);
  #endif
  QApplication app(argc, argv);
  MainWindow *win = new MainWindow();
  QImage qi(":/thing.png");
  if(qi.width() != 640) {
      return 1;
  }
  QImage qi2(":/thing2.png");
  if(qi2.width() != 640) {
      return 1;
  }
  win->setWindowTitle("Meson Qt5 build test");
  QLabel *label_stuff = win->findChild<QLabel *>("label_stuff");
  if(label_stuff == nullptr) {
      return 1;
  }
  int w = label_stuff->width();
  int h = label_stuff->height();
  label_stuff->setPixmap(QPixmap::fromImage(qi).scaled(w,h,Qt::KeepAspectRatio));
  QLabel *label_stuff2 = win->findChild<QLabel *>("label_stuff2");
  if(label_stuff2 == nullptr) {
      return 1;
  }
  w = label_stuff2->width();
  h = label_stuff2->height();
  label_stuff2->setPixmap(QPixmap::fromImage(qi2).scaled(w,h,Qt::KeepAspectRatio));
  win->show();
  return app.exec();
  return 0;
}
