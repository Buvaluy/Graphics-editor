#ifndef DIALOGTEXT_H
#define DIALOGTEXT_H

#include <QDialog>

namespace Ui {
class DialogText;
}

class DialogText : public QDialog
{
    Q_OBJECT

public:
    explicit DialogText(QWidget *parent = 0);
    ~DialogText();

    QString getText();

private:
    Ui::DialogText *ui;
    QString text;
};

#endif // DIALOGTEXT_H
