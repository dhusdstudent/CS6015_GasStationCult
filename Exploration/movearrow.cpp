#include "movearrow.h"

MoveArrow::MoveArrow(SceneID id) : target(id) {
    setAcceptedMouseButtons(Qt::LeftButton);
}

void MoveArrow::mousePressEvent(QGraphicsSceneMouseEvent *event){
    Viewpoint *point = dynamic_cast<Viewpoint*>(scene());
    if (point){
        point->loadScene(target);
    }
}
