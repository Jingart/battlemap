#include "battlemap.h"
#include <QDesktopWidget>
#include <QApplication>
#include "window.h"
#include "mainwindow.h"

void center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 500;
  int HEIGHT = 400;


  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();

  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  //Window mwin;
  MainWindow mwin;
  center(mwin);
  mwin.show();
  //battlemap window(mwindow,1,1);

  //mwindow.setWindowTitle("Lines");
  //mwindow.show();
  //window.show();
  //center(window);

  return app.exec();
}
