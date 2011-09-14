#include "window.h"
#include <QtGui>


Window::Window()
{
    //QWidget *widget = new QWidget;
    //setCentralWidget(widget);

    listView = new QListView();
    new QListViewItem( listView, "(1, 1)", "(1, 2)", "(1, 3)" );
    //treeWidget = new QTreeWidget(this);

    /*QTreeWidgetItem *cities = new QTreeWidgetItem(treeWidget);
    cities->setText(0, tr("Cities"));
    QTreeWidgetItem *osloItem = new QTreeWidgetItem(cities);
    osloItem->setText(0, tr("Oslo"));
    osloItem->setText(1, tr("Yes"));*/

    mbwindow = new battlemap();
    //label = new QLabel(tr("Laber &Label:"));
    //button = new QPushButton(tr("&Button"));


    QGridLayout *mainLayout = new QGridLayout;
    //mainLayout->setColumnStretch(1, 1);
    //mainLayout->setRowStretch(0, 10);
    //mainLayout->setColumnStretch(3, 1);
    //mainLayout->addWidget(mbwindow, 0, 0, 1, 4);
    //mainLayout->setRowMinimumHeight(1, 6);
    //mainLayout->addWidget(label, 2, 1, Qt::AlignRight);
    //mainLayout->addWidget(button, 2, 2);
    //mainLayout->addWidget(treeWidget, 0, 1);

    mainLayout->addWidget(listView, 0, 0);
    mainLayout->addWidget(mbwindow, 0, 1, 2, 2);


    setLayout(mainLayout);



}
