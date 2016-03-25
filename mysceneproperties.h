#ifndef MYSCENEPROPERTIES_H
#define MYSCENEPROPERTIES_H

#include <QPen>
#include <QColor>
#include <QObject>
#include <qgraphicsscene.h>
#include <qobject.h>
#include <qgraphicsscene.h>
#include <QGraphicsSceneMouseEvent>
#include <list>
#include <qdebug.h>
#include <QGraphicsItem>
#include <QPushButton>
#include <QApplication>
#include <QDesktopWidget>

using namespace std;

class  MySceneProperties : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MySceneProperties(QObject *parent = 0);

    void setTool(const int tool);
    void setSizePen(const int size);
    void setStylePen();
    void setColorPen1(const QColor color);
    void setColorPen2(const QColor color);
    void setIndexStyle(const int index);
    void setIndexFigure(const int index);
    void setIndexCap(const int index);
    void setIndexCounter(const int index);
    void setCapStylesFigure();
    void setBrushPen(QPen &pen, QBrush &brush);
    void setZ(int value);
    void setButtonBackForward(QPushButton *pb, QPushButton *pf);
    void setButtonColor(QPushButton *pbc1, QPushButton *pbc2);

protected:
    int tool;
    int indextStyle;
    int indextFigure;
    int indextCounter;
    int indextCap;
    int z;
    int x, y;

    bool leftMousePress;
    bool rightMousePress;

    QPen pen1;
    QPen pen2;
    QPen penExcrete;
    QPen pen;
    QBrush brush;

    QPushButton *pb, *pf;
    QPushButton *pbc1, *pbc2;
};

#endif // MYSCENEPROPERTIES_H
