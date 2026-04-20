#ifndef VIEWPOINT_H
#define VIEWPOINT_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QTimer>

enum SceneID {
    Scene01,
    Scene02,
    Scene03,
    Scene04,
    Scene05,
    Scene06,
    Scene07,
    Scene08,
    Scene09,
    Scene10,
    Scene11,
    Scene12,
    Scene13,
    Scene14
};


class Viewpoint : public QGraphicsScene
{
public:
    Viewpoint();

    void loadScene(SceneID id);
};

#endif // VIEWPOINT_H
