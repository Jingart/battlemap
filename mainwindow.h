#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "window.h"

class QMenu;
class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void newMap();
    //void close();

private:
    QAction *newAct;
    QAction *exitAct;
    QMenu *fileMenu;
    //window *asd;

};



#endif // MAINWINDOW_H
