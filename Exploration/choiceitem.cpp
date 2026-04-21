#include "choiceitem.h"
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

ChoiceItem::ChoiceItem(const QString &label,
                       std::function<void()> callback,
                       QGraphicsItem *parent)
    : QGraphicsTextItem(label, parent)
    , m_callback(callback)
{
    setDefaultTextColor(Qt::white);
    setAcceptHoverEvents(true);
    setCursor(Qt::PointingHandCursor);
}

void ChoiceItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    if (m_callback)
        m_callback();
}

void ChoiceItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    setDefaultTextColor(Qt::yellow);
}

void ChoiceItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    setDefaultTextColor(Qt::white);
}