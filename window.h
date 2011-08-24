#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include "battlemap.h"
class QLabel;
class QPushButton;

class window : public QWidget
{
    Q_OBJECT

public:
    window();
private:
    battlemap *mbwindow;
    QLabel *label;
    QPushButton *button;
};

#endif // WINDOW_H
