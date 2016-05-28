#include "mygraphicsitem.h"

MyGraphicsItem::MyGraphicsItem(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

MyGraphicsItem::~MyGraphicsItem()
{

}

void MyGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void MyGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
        Q_UNUSED(event);
}

void MyGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
        Q_UNUSED(event);
}
