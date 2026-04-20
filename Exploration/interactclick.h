#ifndef INTERACTCLICK_H
#define INTERACTCLICK_H

#include "clickable.h"

class InteractData;
class InteractWindow;

// A clickable that opens the InteractWindow with some data.
// Does NOT own its InteractData — the ScreenView or scene data does.
class InteractClick : public Clickable
{
public:
    explicit InteractClick(InteractData *data,           // Not owned
                           InteractWindow *window,       // Not owned
                           QGraphicsItem *parent = nullptr);

    void onClick() override;

    // Optionally set a highlight pixmap shown on hover
    void setHighlightPixmap(const QPixmap &pixmap);

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

private:
    InteractData *m_data;           // Aggregated, not owned
    InteractWindow *m_window;       // Aggregated, not owned
    QPixmap m_normalPixmap;
    QPixmap m_highlightPixmap;
};

#endif // INTERACTCLICK_H