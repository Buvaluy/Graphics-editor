#ifndef MYSCENETOOL_H
#define MYSCENETOOL_H

#include "mysceneproperties.h"


struct HistoryPencil{
    list<QGraphicsItem*> hist;
};

class MySceneTool : public MySceneProperties
{
    Q_OBJECT
public:
    explicit MySceneTool(QObject *parent = 0);

    void mouseMoveArrow(QGraphicsSceneMouseEvent *event);
    void mouseMovePencil(QGraphicsSceneMouseEvent *event);
    void mouseMoveFigure(QGraphicsSceneMouseEvent *event);
    void mouseMoveExcrete(QGraphicsSceneMouseEvent *event);

    void mousePressArrow();
    void mousePressPencil(QGraphicsSceneMouseEvent *event);
    void mousePressFigure(QGraphicsSceneMouseEvent *event);
    void mousePressExcrete(QGraphicsSceneMouseEvent *event);

    void mouseReleasePencil();
    void mouseReleaseFigure(QGraphicsSceneMouseEvent *event);
    void mouseReleaseExcrete(QGraphicsSceneMouseEvent *event);
    void mouseReleasePipette(QGraphicsSceneMouseEvent *event);

protected:

    list<QGraphicsItem*> history;
    list<QGraphicsItem*> historyOfHistory;
    HistoryPencil histPencilItem;
    list<HistoryPencil> histPencil;
    list<QString> histName;
    vector<int> xyPencil;
    QList<QGraphicsItem *> listSelectedItem; // список выбраных елементов

    QGraphicsItem *grabItem;
    QGraphicsItem *tempItem;
};

#endif // MYSCENETOOL_H
