#ifndef BATTLEMAP_H
#define BATTLEMAP_H


#include <QPainter>
#include <QResizeEvent>
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
    void drawBox(QPen pen, int x, int y);

  protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);



};

#endif
