#ifndef KEYITEM_H
#define KEYITEM_H

#include <QObject>
#include <QPushButton>
#include <QGraphicsPixmapItem>
#include "viewpoint.h"

class KeyItem : public QGraphicsPixmapItem
{
public:
    KeyItem();
    bool isCollected;
    virtual void onClick(Viewpoint *scene) =0;
};

#endif // KEYITEM_H
