#include "myscenetool.h"

MySceneTool::MySceneTool(QObject *parent)
{
    Q_UNUSED(parent);
}

void MySceneTool::mouseMoveArrow(QGraphicsSceneMouseEvent *event)
{
    int testindex = 0;
    while(listSelectedItem.size() > testindex){
        listSelectedItem.at(testindex)->setPos( listSelectedItem.at(testindex)->pos().x() - (event->lastScenePos().x() - event->scenePos().x()),
                                                listSelectedItem.at(testindex)->pos().y() - (event->lastScenePos().y() - event->scenePos().y()));
        ++testindex;
    }
}

void MySceneTool::mouseMovePencil(QGraphicsSceneMouseEvent *event)
{
    tempItem = (QGraphicsItem*)this->addLine(event->lastScenePos().x(), event->lastScenePos().y(),
                                             event->scenePos().x(), event->scenePos().y(), pen);
    histPencilItem.hist.push_back(tempItem);
    tempItem->setZValue(z);
    x = event->scenePos().x();
    y = event->scenePos().y();
    xyPencil.push_back(x);
    xyPencil.push_back(y);
}

void MySceneTool::mouseMoveFigure(QGraphicsSceneMouseEvent *event)
{
    this->setBrushPen(pen, brush);
    this->removeItem(history.back());
    history.pop_back();
    switch(indextFigure){
        case 0:{
            tempItem =  (QGraphicsItem*)this->addLine(x, y, event->scenePos().x(), event->scenePos().y(), pen);
        }
        case 1:{
            tempItem = (QGraphicsItem*)this->addEllipse(x, y, event->scenePos().x() - x, event->scenePos().y() - y, pen, brush);
        }
        case 2:{
            tempItem = (QGraphicsItem*)this->addRect(x, y, event->scenePos().x() - x, event->scenePos().y() - y, pen, brush);
        }
    }
    history.push_back(tempItem);
    tempItem->setZValue(z);
    this->update(this->sceneRect());
}

void MySceneTool::mouseMoveExcrete(QGraphicsSceneMouseEvent *event)
{
    this->removeItem(tempItem);
    tempItem = this->addRect(x, y, event->scenePos().x() - x, event->scenePos().y() - y, penExcrete);
}

void MySceneTool::mousePressArrow()
{

}

void MySceneTool::mousePressPencil(QGraphicsSceneMouseEvent *event)
{
    x = event->scenePos().x();
    y = event->scenePos().y();
    histPencilItem.hist.clear();
    xyPencil.push_back(x);
    xyPencil.push_back(y);
}

void MySceneTool::mousePressFigure(QGraphicsSceneMouseEvent *event)
{
    x = event->scenePos().x();
    y = event->scenePos().y();
    switch(indextFigure){
        case 0:{
            history.push_back((QGraphicsItem*)this->addLine(x, y, x, y, pen));
        }
        case 1:{
            history.push_back((QGraphicsItem*)this->addEllipse(x, y, 0, 0, pen));
        }
        case 2:{
            history.push_back((QGraphicsItem*)this->addRect(x, y, 0, 0, pen));
        }
    }
}

void MySceneTool::mousePressExcrete(QGraphicsSceneMouseEvent *event)
{
    x = event->scenePos().x();
    y = event->scenePos().y();
    tempItem = this->addRect(x, y, 0, 0, penExcrete);
}

void MySceneTool::mouseReleasePencil()
{
    pf->setEnabled(false);
    historyOfHistory.clear();
    QPainterPath pp;
    QPolygon qpol;
    while(xyPencil.size() > 0){
        y = xyPencil.back();
        xyPencil.pop_back();
        x = xyPencil.back();
        xyPencil.pop_back();
        qpol << QPoint(x, y);
    }
    pp.addPolygon(qpol);
    tempItem = (QGraphicsItem*)this->addPath(pp, pen);
    history.push_back(tempItem);
    tempItem->setFlag(QGraphicsItem::ItemIsSelectable, true);  //////
    tempItem->setZValue(z);

    while(histPencilItem.hist.size() > 0){
        this->removeItem(histPencilItem.hist.back());
        histPencilItem.hist.pop_back();
    }
}

void MySceneTool::mouseReleaseFigure(QGraphicsSceneMouseEvent *event)
{
    pf->setEnabled(false);
    historyOfHistory.clear();
    this->setBrushPen(pen, brush);
    if(history.size() >= 64)history.pop_front();
    this->removeItem(history.back());
    history.pop_back();
    if(indextFigure == 0){
        tempItem = (QGraphicsItem*)this->addLine(x, y, event->scenePos().x(), event->scenePos().y(), pen);

    }else if(indextFigure == 1){
        tempItem = (QGraphicsItem*)this->addEllipse(x, y, event->scenePos().x() - x, event->scenePos().y() - y, pen, brush);

    }else if(indextFigure == 2){
        tempItem = (QGraphicsItem*)this->addRect(x, y, event->scenePos().x() - x, event->scenePos().y() - y, pen, brush);
    }
    history.push_back(tempItem);
    tempItem->setFlag(QGraphicsItem::ItemIsSelectable, true);  //////
    tempItem->setZValue(z);
}

void MySceneTool::mouseReleaseExcrete(QGraphicsSceneMouseEvent *event)
{
    QPainterPath pp;
    QPolygon qpol;
    qpol << QPoint(x, y);
    qpol << QPoint(event->scenePos().x(), y);
    qpol << QPoint(event->scenePos().x(), event->scenePos().y());
    qpol << QPoint(x, event->scenePos().y());
    qpol << QPoint(x, y);
    pp.addPolygon(qpol);
    this->setSelectionArea(pp);
    listSelectedItem = this->selectedItems();
    this->removeItem(tempItem);
}

void MySceneTool::mouseReleasePipette(QGraphicsSceneMouseEvent *event)
{
    QPixmap okno = QPixmap::grabWindow(QApplication::desktop()->winId());
    QImage image = okno.toImage();
    QRgb col = image.pixel(event->screenPos().x(), event->screenPos().y());
    QColor qcol;
    qcol.setRgb(col);
    if(leftMousePress){
        pen1.setColor(qcol);
        int r,g,b,a;
        qcol.getRgb(&r, &g, &b, &a);
        pbc1->setStyleSheet("background-color: rgb(" + QString::number(r) + "," + QString::number(g) + "," + QString::number(b) + ")");
    }
    if(rightMousePress){
        pen2.setColor(qcol);
        int r,g,b,a;
        qcol.getRgb(&r, &g, &b, &a);
        pbc2->setStyleSheet("background-color: rgb(" + QString::number(r) + "," + QString::number(g) + "," + QString::number(b) + ")");
    }
}
