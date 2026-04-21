#ifndef CHOICEITEM_H
#define CHOICEITEM_H

#include <QGraphicsTextItem>
#include <functional>

// A clickable text item representing one player choice.
// Calls a callback when clicked, keeping InteractWindow
// out of the event handling business.
class ChoiceItem : public QGraphicsTextItem
{
public:
    explicit ChoiceItem(const QString &label,
                        std::function<void()> callback,
                        QGraphicsItem *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

private:
    std::function<void()> m_callback;
};

#endif // CHOICEITEM_H