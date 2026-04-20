#include "item.h"

item::item() {}

void item::onClick(Viewpoint *scene){
    //scene->addToInventory(this);
    scene->removeItem(this);
}