#include "mygraphicsscene.h"

MyGraphicsScene::MyGraphicsScene(QObject *parent)
{
    Q_UNUSED(parent);
    pen1.setCapStyle(Qt::RoundCap);
    pen2.setCapStyle(Qt::RoundCap);
    leftMousePress = false;
    rightMousePress = false;
    penExcrete.setStyle(Qt::DotLine);
}



void MyGraphicsScene::delItem()
{
    if(history.size() == 0)return;
    historyOfHistory.push_back(history.back());
    this->removeItem(history.back());
    history.pop_back();
    if(history.size() == 0)
        pb->setEnabled(false);
    this->update(this->sceneRect());
    pf->setEnabled(true);
}

void MyGraphicsScene::retItem()
{
    this->addItem(historyOfHistory.back());
    history.push_back(historyOfHistory.back());
    historyOfHistory.pop_back();
    pb->setEnabled(true);
    if(historyOfHistory.size() == 0)
        pf->setEnabled(false);
}

void MyGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(leftMousePress){
        pen = pen1;
    }else if(rightMousePress){
        pen = pen2;
    }else{
        return;
    }

    switch(tool){
    case 1:{
        this->mouseMovePencil(event);
        break;
    }
    case 2:{
        this->mouseMoveFigure(event);
        break;
    }
    case 0:{
        this->mouseMoveArrow(event);
        break;
    }
    case 3:{
        this->mouseMoveExcrete(event);
        break;
    }
    }

    this->update(this->sceneRect());
}

void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent  *event)
{
    if(event->button() == Qt::LeftButton){
        leftMousePress = true;
        pen = pen1;
    }else if(event->button() == Qt::RightButton){
        rightMousePress = true;
        pen = pen2;
    }
    switch(tool){
    case 1:{
        this->mousePressPencil(event);
        break;
    }
    case 2:{
        this->mousePressFigure(event);
        break;
    }
    case 0:{

    }
    case 3:{
        this->mousePressExcrete(event);
        break;
    }
//    case 5:{
//        this->mousePressText(event);
//        break;
//    }
    }
   // this->update(this->sceneRect());
    this->update(-1000,-1000, 3000,3000);
}

void MyGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent  *event)
{
    if(event->button() == Qt::LeftButton){
        pen = pen1;
    }else if(event->button() == Qt::RightButton){
        pen = pen2;
    }
    switch(tool){
    case 1:{
        this->mouseReleasePencil();
        break;
    }
    case 2:{
        this->mouseReleaseFigure(event);
        break;
    }
    case 3:{
        this->mouseReleaseExcrete(event);
        break;
    }
    case 4:{
        this->mouseReleasePipette(event);
        break;
    }
    case 5:{
        this->mouseReleaseText(event);
        break;
    }
    //default: {break;}
    }
    if(history.size() > 0)
        pb->setEnabled(true);
    leftMousePress = false;
    rightMousePress = false;
    this->update(this->sceneRect());

}


