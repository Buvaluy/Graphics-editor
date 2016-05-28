#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::setItemsComboBoxStyle()
{
    QIcon iconZoomButton1, iconZoomButton2, iconZoomButton3, iconZoomButton4, iconZoomButton5;
    iconZoomButton1.addFile(":/images/stylePen/solid.PNG");
    ui->comboBoxPenStyle->addItem(iconZoomButton1, "");
    iconZoomButton2.addFile(":/images/stylePen/dash.PNG");
    ui->comboBoxPenStyle->addItem(iconZoomButton2, "");
    iconZoomButton3.addFile(":/images/stylePen/dot.PNG");
    ui->comboBoxPenStyle->addItem(iconZoomButton3, "");
    iconZoomButton4.addFile(":/images/stylePen/dashdot.PNG");
    ui->comboBoxPenStyle->addItem(iconZoomButton4, "");
    iconZoomButton5.addFile(":/images/stylePen/dashdotdotline.PNG");
    ui->comboBoxPenStyle->addItem(iconZoomButton5, "");
    ui->comboBoxPenStyle->setIconSize(QSize(90, 20));
}



void MainWindow::setItemsComboBoxFigure()
{
    QIcon iconZoomButton1, iconZoomButton2, iconZoomButton3;
    iconZoomButton1.addFile(":/images/figure/line.PNG");
    ui->comboBoxFigure->addItem(iconZoomButton1, "");
    iconZoomButton2.addFile(":/images/figure/elipse.PNG");
    ui->comboBoxFigure->addItem(iconZoomButton2, "");
    iconZoomButton3.addFile(":/images/figure/rect.PNG");
    ui->comboBoxFigure->addItem(iconZoomButton3, "");
    ui->comboBoxFigure->setIconSize(QSize(20, 30));
}


void MainWindow::setItemsComboBoxCouner()
{
    QIcon iconZoomButton1, iconZoomButton2, iconZoomButton3;
    iconZoomButton1.addFile(":/images/button/counter.png");
    ui->comboBoxCounter->addItem(iconZoomButton1, "");
    iconZoomButton2.addFile(":/images/button/inside.png");
    ui->comboBoxCounter->addItem(iconZoomButton2, "");
    iconZoomButton3.addFile(":/images/button/counterInside.png");
    ui->comboBoxCounter->addItem(iconZoomButton3, "");
    ui->comboBoxCounter->setIconSize(QSize(20, 18));
}


void MainWindow::setItemsComboBoxCapStyle()
{
    QIcon iconZoomButton1, iconZoomButton2;
    iconZoomButton1.addFile(":/images/button/round.png",QSize(15,15));
    ui->comboBoxCapStyle->addItem(iconZoomButton1, "");
    iconZoomButton2.addFile(":/images/button/rect.png", QSize(20,20));
    ui->comboBoxCapStyle->addItem(iconZoomButton2, "");
    //ui->comboBoxCapStyle->setIconSize(QSize(20, 20));
}

void MainWindow::setItemsButtonIcon()
{
    ui->pushButtonBack->setIcon(QIcon(":/images/button/back.png"));
    ui->pushButtonBack->setFlat(true);
    ui->pushButtonBack->setEnabled(false);
    ui->pushButtonForward->setIcon(QIcon(":/images/button/forward.png"));
    ui->pushButtonForward->setFlat(true);
    ui->pushButtonForward->setEnabled(false);

    ui->pushButtonZ1->setIcon(QIcon(":/images/button/z1.png"));
    ui->pushButtonZ1->setIconSize(QSize(32, 32));
    ui->pushButtonZ1->setFlat(true);
    ui->pushButtonZ2->setIcon(QIcon(":/images/button/z2.png"));
    ui->pushButtonZ2->setIconSize(QSize(32, 32));
    ui->pushButtonZ2->setFlat(true);
    ui->pushButtonZ3->setIcon(QIcon(":/images/button/z3.png"));
    ui->pushButtonZ3->setIconSize(QSize(32, 32));
    ui->pushButtonZ3->setFlat(true);
}


void MainWindow::buttonMode(int tool)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    switch(tool){
    case 1: { // pencil
        this->actionToolEnable();
        ui->actionPencil->setEnabled(false);
        this->comboBoxFigureHide();
        break;
    }
    case 2: { // figure
        this->actionToolEnable();
        ui->actionFigure->setEnabled(false);
        ui->comboBoxCapStyle->show();
        ui->comboBoxCounter->show();
        ui->comboBoxFigure->show();
        ui->comboBoxPenStyle->show();
        break;
    }
    case 3: { // excrete
        this->actionToolEnable();
        ui->actionExcrete->setEnabled(false);
        this->comboBoxFigureHide();
        break;
    }
    case 0: { // arrow
        this->actionToolEnable();
        ui->actionArrow->setEnabled(false);
        this->comboBoxFigureHide();
        this->setCursor(QCursor(Qt::ClosedHandCursor));
        return;
    }
    case 4: { // pipette
        this->actionToolEnable();
        ui->actionPepette->setEnabled(false);
        this->comboBoxFigureHide();
        this->setCursor(QCursor(Qt::CrossCursor));
        return;
    }
    case 5: { // text
        this->actionToolEnable();
        ui->actionText->setEnabled(false);
        this->comboBoxFigureHide();
        this->setCursor(QCursor(Qt::IBeamCursor));
        return;
    }
    }
    QPainterPath pp;
    pp.addRect(0, 0, 0, 0);
    scene->setSelectionArea(pp);
}

void MainWindow::comboBoxFigureHide()
{
    ui->comboBoxCapStyle->hide();
    ui->comboBoxCounter->hide();
    ui->comboBoxFigure->hide();
    ui->comboBoxPenStyle->hide();
}

void MainWindow::actionToolEnable()
{
    ui->actionPencil->setEnabled(true);
    ui->actionFigure->setEnabled(true);
    ui->actionExcrete->setEnabled(true);
    ui->actionArrow->setEnabled(true);
    ui->actionPepette->setEnabled(true);
    ui->actionText->setEnabled(true);
}
