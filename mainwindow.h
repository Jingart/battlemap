#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "window.h"

class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private:
    QMenu *fileMenu;
    //window *asd;

};



#endif // MAINWINDOW_H
