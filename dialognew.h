#ifndef DIALOGNEW_H
#define DIALOGNEW_H

#include <QDialog>

class QCheckBox;
class QLabel;
class QSpinBox;
class QPushButton;

class DialogNew : public QDialog
{

public:
    DialogNew();
    int getColumnCount();
    int getRowCount();

private:
    int hight;
    int width;
    QLabel *label;
    QSpinBox *spinBoxRows;
    QSpinBox *spinBoxColumns;
    QPushButton *okButton;
    QPushButton *closeButton;
};



#endif // DIALOGNEW_H
