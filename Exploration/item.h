#ifndef ITEM_H
#define ITEM_H
#include "keyitem.h"
#include "viewpoint.h"

class item : public KeyItem
{
public:
    item();
    //void onClick(Viewpoint *scene) override;
    bool isCollected = false;
};

#endif // ITEM_H
