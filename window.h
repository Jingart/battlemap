#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
//#include <QMainWindow>
#include "battlemap.h"
class QLabel;
class QPushButton;
class QMenu;
class QListView;

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
    QListView *listView;
    battlemap *mbwindow;
    QLabel *label;
    QPushButton *button;

};

#endif // WINDOW_H
