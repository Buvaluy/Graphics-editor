#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Painter");
    scene = new MyGraphicsScene();
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    scene->setButtonBackForward(ui->pushButtonBack, ui->pushButtonForward);
    scene->setButtonColor(ui->buttonColor1, ui->buttonColor2);
    scene->setSceneRect(ui->graphicsView->rect().x(), ui->graphicsView->rect().y(), ui->graphicsView->rect().width()-5, ui->graphicsView->rect().height()-5);
    scene->setColorPen1(QColor(0, 0, 0));
    scene->setColorPen2(QColor(255, 255, 255));
    setWindowIcon(QIcon(":/images/toolBar/figure.png"));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(300, 300);
    ui->centralWidget->setMinimumHeight(ui->graphicsView->height());
    ui->centralWidget->setMinimumWidth(ui->graphicsView->width());

    ui->buttonColor2->setStyleSheet("background-color: rgb(" + QString::number(255) + "," + QString::number(255) + "," + QString::number(255) + ")");
    ui->buttonColor1->setStyleSheet("background-color: rgb(" + QString::number(0) + "," + QString::number(0) + "," + QString::number(0) + ")");
    ui->spinBoxPenWidth->setRange(1,64);

    ui->graphicsView->setFixedHeight(300);
    ui->graphicsView->setFixedWidth(600);
    //ui->graphicsView->scene()->setSceneRect();
    //setGeometry(geometry().x(), geometry().y(), d->getW(), d->getH());
    this->setFixedHeight(300+110);

    this->setFixedWidth(650);
    scene->setSceneRect(ui->graphicsView->rect().x(), ui->graphicsView->rect().y(), ui->graphicsView->rect().width()-5, ui->graphicsView->rect().height()-5);


    this->setItemsComboBoxStyle();
    this->setItemsComboBoxFigure();
    this->setItemsComboBoxCouner();
    this->setItemsComboBoxCapStyle();
    this->setItemsButtonIcon();
    this->on_actionPencil_triggered();
    this->on_pushButtonZ2_clicked();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_buttonColor2_clicked()
{
    QColor color = QColorDialog::getColor();
    if(!color.isValid()){
        return;
    }
    scene->setColorPen2(color);
    int r,g,b,a;
    color.getRgb(&r, &g, &b, &a);
    ui->buttonColor2->setStyleSheet("background-color: rgb(" + QString::number(r) + "," + QString::number(g) + "," + QString::number(b) + ")");
}

void MainWindow::on_buttonColor1_clicked()
{
    QColor color = QColorDialog::getColor();
    if(!color.isValid()){
        return;
    }
    scene->setColorPen1(color);
    int r,g,b,a;
    color.getRgb(&r, &g, &b, &a);
    ui->buttonColor1->setStyleSheet("background-color: rgb(" + QString::number(r) + "," + QString::number(g) + "," + QString::number(b) + ")");
}

void MainWindow::on_spinBoxPenWidth_editingFinished()
{
    scene->setSizePen(ui->spinBoxPenWidth->value());
}

void MainWindow::on_comboBoxPenStyle_currentIndexChanged(int index)
{
    scene->setIndexStyle(index);
}

void MainWindow::on_comboBoxFigure_currentIndexChanged(int index)
{
    scene->setIndexFigure(index);
}

void MainWindow::on_pushButtonBack_clicked()
{
    scene->delItem();
}

void MainWindow::on_comboBoxCapStyle_currentIndexChanged(int index)
{
    scene->setIndexCap(index);
}

void MainWindow::on_comboBoxCounter_currentIndexChanged(int index)
{
    scene->setIndexCounter(index);
}


void MainWindow::on_pushButtonZ1_clicked()
{
    scene->setZ(1);
    ui->pushButtonZ1->setEnabled(false);
    ui->pushButtonZ2->setEnabled(true);
    ui->pushButtonZ3->setEnabled(true);
}

void MainWindow::on_pushButtonZ2_clicked()
{
    scene->setZ(2);
    ui->pushButtonZ1->setEnabled(true);
    ui->pushButtonZ2->setEnabled(false);
    ui->pushButtonZ3->setEnabled(true);
}

void MainWindow::on_pushButtonZ3_clicked()
{
    scene->setZ(3);
    ui->pushButtonZ1->setEnabled(true);
    ui->pushButtonZ2->setEnabled(true);
    ui->pushButtonZ3->setEnabled(false);
}

void MainWindow::on_pushButtonForward_clicked()
{
    scene->retItem();
}

void MainWindow::on_actionPepette_triggered()
{
    scene->setTool(4);
    this->buttonMode(4);
}

void MainWindow::on_actionExcrete_triggered()
{
    scene->setTool(3);
    this->buttonMode(3);
}

void MainWindow::on_actionFigure_triggered()
{
    scene->setTool(2);
    this->buttonMode(2);
}

void MainWindow::on_actionPencil_triggered()
{
    scene->setTool(1);
    this->buttonMode(1);
}

void MainWindow::on_actionArrow_triggered()
{
    scene->setTool(0);
    this->buttonMode(0);
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "d:\\",
        tr("Изображение в формате (*.mkp);;Изображение в формате (*.png);;Изображение в формате  (*.jpg);;Изображение в формате  (*.bmp)"));
    //qDebug() << fileName;
    QPixmap pixmap = QPixmap::grabWidget(ui->graphicsView);
    if(fileName.isEmpty())
        return;
    QStringList str = fileName.split(".");
    //qDebug() << str.at(0) << "       " << str.at(1);
    if(str.at(1) == "mkp"){
        QByteArray bArray;
        QBuffer buffer(&bArray);
        buffer.open(QIODevice::WriteOnly);
        pixmap.save(&buffer, "PNG");
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        file.write(buffer.data());
        file.close();
    }else{
        pixmap.save(fileName);
    }
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "d:\\",
        tr("*.mkp *.bmp *.png *.jpg"));
    if(fileName.isEmpty())
        return;
    ui->graphicsView->scene()->clear();
    QPixmap pixmap;
    pixmap.load(fileName);
    ui->graphicsView->scene()->addPixmap(pixmap)->setPos(-2, -2);
    pixmap.rect();
    QRect rect = pixmap.rect();
    ui->graphicsView->setFixedHeight(rect.height());
    ui->graphicsView->setFixedWidth(rect.width());
    this->setFixedHeight(rect.height()+110);
    this->setFixedWidth(rect.width()+50);
    scene->setSceneRect(ui->graphicsView->rect().x(), ui->graphicsView->rect().y(), ui->graphicsView->rect().width()-5, ui->graphicsView->rect().height()-5);
}

void MainWindow::on_actionResize_triggered()
{
    DialogSize *d = new DialogSize(this);
    if(!d->exec() || d->getH() <= 10 || d->getW() <= 10){
        delete(d);
        return;
    }
    ui->graphicsView->setFixedHeight(d->getH());
    ui->graphicsView->setFixedWidth(d->getW());
    //ui->graphicsView->scene()->setSceneRect();
    //setGeometry(geometry().x(), geometry().y(), d->getW(), d->getH());
    this->setFixedHeight(d->getH()+110);
    if(d->getW()+50 < 550)
        this->setFixedWidth(550);
    else
        this->setFixedWidth(d->getW()+50);
    scene->setSceneRect(ui->graphicsView->rect().x(), ui->graphicsView->rect().y(), ui->graphicsView->rect().width()-5, ui->graphicsView->rect().height()-5);

    delete(d);
}

void MainWindow::on_actionText_triggered()
{
    scene->setTool(5);
    this->buttonMode(5);
    bool bOk;
    QFont fnt = QFontDialog::getFont(&bOk);
    if(!bOk) {
        return;
    }
    scene->setFont(fnt);
    QString text;
    DialogText *dt = new DialogText();
    if(!dt->exec()){
        delete(dt);
        return;
    }
    text = dt->getText();
    delete(dt);
    scene->setText(text);
}

void MainWindow::on_actionNEw_triggered()
{
    ui->graphicsView->scene()->clear();
    ui->graphicsView->scene()->update(-1000, -1000, 3000, 3000);
}
