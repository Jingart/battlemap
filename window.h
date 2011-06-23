#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
//#include <QMainWindow>
#include "battlemap.h"
class QLabel;
class QPushButton;
class QMenu;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();
private:
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *formatMenu;
    QMenu *helpMenu;
    battlemap *mbwindow;
    QLabel *label;
    QPushButton *button;
};

#endif // WINDOW_H
