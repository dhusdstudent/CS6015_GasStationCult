#include "interactwindow.h"
#include "interactdata.h"
#include "choice.h"
#include "gamemanager.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

InteractWindow::InteractWindow(GameManager *manager, QGraphicsItem *parent)
    : QGraphicsItem(parent)
    , m_manager(manager)
    , m_currentData(nullptr)
    , m_visible(false)
    , m_textItem(new QGraphicsTextItem(this))
{
    setVisible(false);
    setZValue(10);  // Always on top
    m_textItem->setPos(16, 16);
    m_textItem->setTextWidth(W - 32);
    m_textItem->setDefaultTextColor(Qt::white);
}

void InteractWindow::display(InteractData *data)
{
    m_currentData = data;
    m_visible = true;
    setVisible(true);

    m_textItem->setPlainText(data ? data->text() : QString());
    buildChoiceItems();
    update();
}

void InteractWindow::hide()
{
    m_visible = false;
    m_currentData = nullptr;
    setVisible(false);
    clearChoiceItems();
}

QRectF InteractWindow::boundingRect() const
{
    return QRectF(0, 0, W, H);
}

void InteractWindow::paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *,
                           QWidget *)
{
    if (!m_visible) return;
    painter->setBrush(QColor(20, 20, 20, 210));
    painter->setPen(QColor(180, 180, 180));
    painter->drawRoundedRect(boundingRect(), 8, 8);
}

void InteractWindow::buildChoiceItems()
{
    clearChoiceItems();
    if (!m_currentData) return;

    const auto &choices = m_currentData->choices();
    for (int i = 0; i < choices.size(); ++i) {
        // Lambda captures i by value so each item has its own index
        auto *item = new ChoiceItem(
            choices[i]->label(),
            [this, i]() { onChoiceSelected(i); },
            this
            );

        item->setPos(16, 80 + i * 28);
        m_choiceItems.append(item);
    }
}

void InteractWindow::clearChoiceItems()
{
    for (auto *item : m_choiceItems)
        delete item;
    m_choiceItems.clear();
}

void InteractWindow::onChoiceSelected(int index)
{
    if (!m_currentData) return;
    const auto &choices = m_currentData->choices();
    if (index < 0 || index >= choices.size()) return;

    Choice *choice = choices[index];

    switch (choice->type()) {
    case ChoiceType::GET:
        m_manager->addFlag(choice->typeData());
        break;
    case ChoiceType::FLAG:
        m_manager->addFlag(choice->typeData());
        break;
    case ChoiceType::TALK:
        if (choice->nextData())
            display(choice->nextData());
        else
            hide();
        break;
    case ChoiceType::CLOSE:
        hide();
        break;
    case ChoiceType::SCENE_CHANGE:
        m_manager->changeScreen(choice->typeData().toInt());
        break;
    }
}