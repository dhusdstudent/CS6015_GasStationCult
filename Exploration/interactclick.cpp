#include "interactclick.h"
#include "interactwindow.h"
#include "interactdata.h"

InteractClick::InteractClick(InteractData *data,
                             InteractWindow *window,
                             QGraphicsItem *parent)
    : Clickable(parent)
    , m_data(data)
    , m_window(window)
{
    setAcceptHoverEvents(true);
}

void InteractClick::onClick()
{
    if (m_window && m_data)
        m_window->display(m_data);
}

void InteractClick::setHighlightPixmap(const QPixmap &pixmap)
{
    m_highlightPixmap = pixmap;
}

void InteractClick::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    if (!m_highlightPixmap.isNull())
        setPixmap(m_highlightPixmap);
}

void InteractClick::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    if (!m_highlightPixmap.isNull())
        setPixmap(m_normalPixmap);
}