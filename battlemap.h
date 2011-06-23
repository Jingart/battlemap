#ifndef BATTLEMAP_H
#define BATTLEMAP_H

//class battlemap
//{
//public:
//    battlemap();
//};

//#endif // BATTLEMAP_H


//#ifndef LINES_H
//#define LINES_H
#include <QPainter>
#include <QWidget>

class battlemap : public QWidget
{
  Q_OBJECT

  public:
    battlemap(QWidget *parent = 0);
    battlemap(int x, int y);
    battlemap(QWidget *parent, int rows, int columns);

  private:
    void drawMapWindow();
    void InitializeMatrix();
    QPoint WindowCenter();

  protected:
    void paintEvent(QPaintEvent *event);
    void drawBox(QPen pen, int x, int y);


};

#endif
