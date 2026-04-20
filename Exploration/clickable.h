#ifndef CLICKABLE_H
#define CLICKABLE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QRect>

// Abstract base for anything clickable in a scene.
// Subclasses must implement onClick().
class Clickable : public QGraphicsPixmapItem
{
public:
    explicit Clickable(QGraphicsItem *parent = nullptr);
    virtual ~Clickable() = default;

    virtual void onClick() = 0;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // CLICKABLE_H