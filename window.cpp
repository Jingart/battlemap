#include "window.h"
#include <QtGui>


Window::Window()
{

    listView = new QListView();
    listView->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    //mbwindow = new battlemap(2, 2);
    //mbwindow->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //SetupGridLayout();

}

void Window::SetupGridLayout()
{
    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->setSpacing(5);

    //mainLayout->setRowStretch(0, 10);
    //mainLayout->setColumnStretch(3, 1);
    //mainLayout->setRowMinimumHeight(1, 6);

    mainLayout->addWidget(listView, 0, 0);
    mainLayout->addWidget(mbwindow, 0, 1, 2, 2);

    setLayout(mainLayout);
}

void Window::SetupNewBattlemap(int x, int y)
{
    mbwindow = new battlemap(x, y);
    SetupGridLayout();
}







