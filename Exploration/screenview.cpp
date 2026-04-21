#include "screenview.h"
#include "clickable.h"
#include "gamemanager.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QBrush>
#include <QImage>

ScreenView::ScreenView(const QString &backgroundPath,
                       GameManager *manager,
                       QObject *parent)
    : QGraphicsScene(parent)
    , m_manager(manager)
    , m_backgroundPath(backgroundPath)
{
    setSceneRect(0, 0, 908, 690);
    loadBackground();
}

ScreenView::~ScreenView()
{
    // QGraphicsScene removes items from the scene, but doesn't delete
    // items it didn't allocate. We track and delete our own clickables.
    qDeleteAll(m_clickables);
}

void ScreenView::loadBackground()
{
    QImage bg(m_backgroundPath);
    if (!bg.isNull())
        setBackgroundBrush(QBrush(bg.scaled(908, 690, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
}

void ScreenView::addClickable(Clickable *clickable, qreal x, qreal y)
{
    m_clickables.append(clickable);
    addItem(clickable);
    clickable->setPos(x, y);
}

void ScreenView::render()
{
    // Subclasses or lambda-based setup can use this hook to
    // show/hide clickables based on current flags.
    // Basic implementation: all clickables visible by default.
    for (Clickable *c : m_clickables)
        c->setVisible(true);
}