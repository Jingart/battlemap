#include "dialognew.h"
#include <QtGui>

DialogNew::DialogNew()
{
    label = new QLabel(tr("Find &what:"));

    okButton = new QPushButton(tr("&Ok"));
    closeButton = new QPushButton(tr("&Close"));

    spinBoxRows = new QSpinBox();
    spinBoxColumns = new QSpinBox();

    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->setSpacing(5);

    mainLayout->addWidget(label, 0, 0);
    mainLayout->addWidget(spinBoxRows, 1, 0);
    mainLayout->addWidget(spinBoxColumns, 1, 1);
    mainLayout->addWidget(okButton, 2, 0);
    mainLayout->addWidget(closeButton, 2, 1);

    setLayout(mainLayout);

    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
}

int DialogNew::getColumnCount()
{
    return spinBoxColumns->value();
}

int DialogNew::getRowCount()
{
    return spinBoxRows->value();
}
