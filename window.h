#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include "battlemap.h"
class QLabel;
class QPushButton;
class QMenu;
class QListView;
class QTreeWidget;
class QListViewItem;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();
    void SetupNewBattlemap();
private:
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *formatMenu;
    QMenu *helpMenu;
    battlemap *mbwindow;
    QLabel *label;
    QPushButton *button;
    QListView *listView;
    QTreeWidget *treeWidget;

};

#endif // WINDOW_H
