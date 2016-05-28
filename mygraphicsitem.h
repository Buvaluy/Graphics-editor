#ifndef MYGRAPHICSITEM_H
#define MYGRAPHICSITEM_H

#include <QGraphicsItem>
#include <qobject.h>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

class MyGraphicsItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MyGraphicsItem(QObject *parent = 0);
    ~MyGraphicsItem();

private:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYGRAPHICSITEM_H
