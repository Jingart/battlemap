#include "mainwindow.h"
#include <QtGui>
#include "window.h"

MainWindow::MainWindow()
{
    mainwidget = new Window;
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

    newAct = new QAction(tr("&New.."), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new Battlemap"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newMap()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(exitAct);
    //http://doc.qt.nokia.com/latest/mainwindows-menus-mainwindow-cpp.html
    setMinimumSize(1000, 700);

}

void MainWindow::newMap()
{
    //infoLabel->setText(tr("Invoked <b>File|New</b>"));
    bool ok;
    /*QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                         tr("User name:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);*/

    newdialog = new DialogNew();
    //newdialog->show();
    newdialog->exec();

    mainwidget->SetupNewBattlemap(4, 4);



}
