#include "window.h"
#include <QtGui>

Window::Window()
{
    //QWidget *widget = new QWidget;
    //setCentralWidget(widget);

    mbwindow = new battlemap();
    label = new QLabel(tr("Laber &Label:"));
    button = new QPushButton(tr("&Button"));

    //m_treeView = new QListView();

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(mbwindow, 0, 0, 1, 4);
    mainLayout->setRowMinimumHeight(1, 6);
    mainLayout->addWidget(label, 2, 1, Qt::AlignRight);
    mainLayout->addWidget(button, 2, 2);
    setLayout(mainLayout);



}
