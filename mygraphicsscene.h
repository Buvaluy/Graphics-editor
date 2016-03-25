#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H



#include "myscenetool.h"


class MyGraphicsScene : public MySceneTool
{
    Q_OBJECT
public:
    explicit  MyGraphicsScene(QObject *parent = 0);

    void delItem();
    void retItem();


private:
    // Функция, в которой производится отслеживание положения мыши
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent  *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);



public:











};



#endif // MYGRAPHICSSCENE_H
