#include "clickable.h"

Clickable::Clickable(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{
}

void Clickable::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    onClick();
}