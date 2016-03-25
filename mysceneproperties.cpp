#include "mysceneproperties.h"

MySceneProperties::MySceneProperties(QObject *parent)   :
        QGraphicsScene()
{
    Q_UNUSED(parent);
}


void MySceneProperties::setSizePen(const int size)
{
    pen1.setWidth(size);
    pen2.setWidth(size);
}

void MySceneProperties::setStylePen()
{
    switch(indextStyle){
    case 0: pen1.setStyle(Qt::SolidLine);pen2.setStyle(Qt::SolidLine);break;
    case 1: pen1.setStyle(Qt::DashLine);pen2.setStyle(Qt::DashLine);break;
    case 2: pen1.setStyle(Qt::DotLine);pen2.setStyle(Qt::DotLine);break;
    case 3: pen1.setStyle(Qt::DashDotLine);pen2.setStyle(Qt::DashDotLine);break;
    case 4: pen1.setStyle(Qt::DashDotDotLine);pen2.setStyle(Qt::DashDotDotLine);break;
    }
}

void MySceneProperties::setColorPen1(const QColor color)
{
    pen1.setColor(color);
}

void MySceneProperties::setColorPen2(const QColor color)
{
    pen2.setColor(color);
}

void MySceneProperties::setIndexStyle(const int index)
{
    this->indextStyle = index;
    this->setStylePen();
}

void MySceneProperties::setIndexFigure(const int index)
{
    this->indextFigure = index;
}

void MySceneProperties::setIndexCap(const int index)
{
    this->indextCap = index;
    this->setCapStylesFigure();
}

void MySceneProperties::setIndexCounter(const int index)
{
    this->indextCounter = index;
}

void MySceneProperties::setTool(const int tool)
{
    this->tool = tool;
    if(tool == 2){
        this->setCapStylesFigure();
        this->setStylePen();
    }
    else if(tool == 1){
        pen1.setStyle(Qt::SolidLine);
        pen1.setCapStyle(Qt::RoundCap);
        pen2.setStyle(Qt::SolidLine);
        pen2.setCapStyle(Qt::RoundCap);
    }
}

void MySceneProperties::setCapStylesFigure()
{
    if(indextCap == 0){
        pen1.setCapStyle(Qt::RoundCap);
        pen2.setCapStyle(Qt::RoundCap);
    }
    else if(indextCap == 1){
        pen1.setCapStyle(Qt::SquareCap);
        pen2.setCapStyle(Qt::SquareCap);
    }
}

void MySceneProperties::setBrushPen(QPen &pen, QBrush &brush)
{
    if(indextCounter == 0 && leftMousePress){
        brush.setStyle(Qt::NoBrush);
        return;
    }else if(indextCounter == 0 && rightMousePress){
        brush.setStyle(Qt::NoBrush);
        return;
    }else if(indextCounter == 1 && leftMousePress){
        brush.setColor(pen2.color());
        pen.setStyle(Qt::NoPen);
    }else if(indextCounter == 1 && rightMousePress){
        brush.setColor(pen1.color());
        pen.setStyle(Qt::NoPen);
    }else if(indextCounter == 2 && leftMousePress){
        brush.setColor(pen2.color());
        pen.setColor(pen1.color());
    }else if(indextCounter == 2 && rightMousePress){
        brush.setColor(pen1.color());
        pen.setColor(pen2.color());
    }
    brush.setStyle(Qt::SolidPattern);
}

void MySceneProperties::setZ(int value)
{
    z = value;
}

void MySceneProperties::setButtonBackForward(QPushButton *pb, QPushButton *pf)
{
    this->pb = pb;
    this->pf = pf;
}

void MySceneProperties::setButtonColor(QPushButton *pbc1, QPushButton *pbc2)
{
    this->pbc1 = pbc1;
    this->pbc2 = pbc2;
}
