#include "mainwindow.h"
#include <QtGui>
#include "window.h"

MainWindow::MainWindow()
{
    Window *mainwidget = new Window;
    setCentralWidget(mainwidget);

    /*
    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(topFiller);
    //layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);
    mainwidget->setLayout(layout);
*/

    fileMenu = menuBar()->addMenu(tr("&File"));
    //http://doc.qt.nokia.com/latest/mainwindows-menus-mainwindow-cpp.html
    setMinimumSize(700, 600);

}
