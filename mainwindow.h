#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>

#include "mygraphicsscene.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setItemsComboBoxStyle();
    void setItemsComboBoxFigure();
    void setItemsComboBoxCouner();
    void setItemsComboBoxCapStyle();
    void setItemsButtonIcon();
    void buttonMode(int tool);
    void comboBoxFigureHide();
    void actionToolEnable();

private slots:
   // void on_actionColor_triggered();

  //  void on_labelColor1_linkActivated(const QString &link);

 //   void on_pushButton_clicked();

    void on_buttonColor2_clicked();

    void on_buttonColor1_clicked();

   // void on_sliderWidthPen_actionTriggered(int action);

  //  void on_spinBox_editingFinished();

    void on_spinBoxPenWidth_editingFinished();

    void on_comboBoxPenStyle_currentIndexChanged(int index);

 //   void on_comboBox_currentIndexChanged(int index);

    void on_comboBoxFigure_currentIndexChanged(int index);

    void on_actionFigure_triggered();

    void on_actionPencil_triggered();

    void on_pushButtonBack_clicked();

    void on_comboBoxCapStyle_currentIndexChanged(int index);

    void on_comboBoxCounter_currentIndexChanged(int index);

    void on_actionArrow_triggered();

    void on_actionExcrete_triggered();

    void on_pushButtonZ1_clicked();

    void on_pushButtonZ2_clicked();

    void on_pushButtonZ3_clicked();

    void on_pushButtonForward_clicked();

    void on_actionPepette_triggered();

private:
    Ui::MainWindow *ui;


public:
    MyGraphicsScene *scene;
};

#endif // MAINWINDOW_H
