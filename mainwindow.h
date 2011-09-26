#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "window.h"
#include "dialognew.h"
#include <QMouseEvent>

class QMenu;
class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void newMap();

private:
    QAction *newAct;
    QAction *exitAct;
    QMenu *fileMenu;
    DialogNew *newdialog;
    Window *mainwidget;


};



#endif // MAINWINDOW_H
