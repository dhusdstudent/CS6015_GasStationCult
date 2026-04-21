#ifndef INTERACTWINDOW_H
#define INTERACTWINDOW_H

#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QList>
#include "choiceitem.h"

class InteractData;
class GameManager;

// Floating overlay that displays text and choice buttons.
// Lives inside the QGraphicsScene (added by GameManager on init).
class InteractWindow : public QGraphicsItem
{
public:
    explicit InteractWindow(GameManager *manager, QGraphicsItem *parent = nullptr);

    void display(InteractData *data);   // Show window with this data
    void hide();

    QRectF boundingRect() const override;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

private:
    GameManager *m_manager;
    InteractData *m_currentData;        // Not owned
    bool m_visible;

    void onChoiceSelected(int index);
    void buildChoiceItems();
    void clearChoiceItems();

    QList<ChoiceItem*> m_choiceItems;
    QGraphicsTextItem *m_textItem;

    static constexpr qreal W = 500;
    static constexpr qreal H = 200;
};

#endif // INTERACTWINDOW_H