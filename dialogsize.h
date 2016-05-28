#ifndef DIALOGSIZE_H
#define DIALOGSIZE_H

#include <QDialog>

namespace Ui {
class DialogSize;
}

class DialogSize : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSize(QWidget *parent = 0);
    ~DialogSize();
    qreal getW();
    qreal getH();

private:
    Ui::DialogSize *ui;
    qreal w;
    qreal h;
};

#endif // DIALOGSIZE_H
