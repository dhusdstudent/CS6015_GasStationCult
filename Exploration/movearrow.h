#ifndef MOVEARROW_H
#define MOVEARROW_H
#include <QObject>
#include <QPushButton>
#include <QGraphicsPixmapItem>
#include "viewpoint.h"

class MoveArrow : public QObject, public QPushButton, public QGraphicsPixmapItem
{
private:
    SceneID target;
public:
    MoveArrow(SceneID id);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MOVEARROW_H
