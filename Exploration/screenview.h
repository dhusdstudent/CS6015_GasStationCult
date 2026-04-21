#ifndef SCREENVIEW_H
#define SCREENVIEW_H

#include <QGraphicsScene>
#include <QList>
#include "interactdata.h"

class Clickable;
class GameManager;

// One navigable screen in the game. Owns its Clickable items.
// Pass a GameManager pointer so render() can check flags for
// conditional visibility of clickables.
class ScreenView : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit ScreenView(const QString &backgroundPath,
                        GameManager *manager,
                        QObject *parent = nullptr,
                        InteractData *defaultData = nullptr);
    ~ScreenView();

    // Add a clickable to the scene. ScreenView takes ownership.
    void addClickable(Clickable *clickable, qreal x, qreal y);

    // Re-evaluate flag conditions and show/hide clickables accordingly.
    // Call this whenever a flag changes.
    void render();

    InteractData* getDefaultData();

private:
    GameManager *m_manager;             // Not owned
    QList<Clickable*> m_clickables;     // Owned
    QString m_backgroundPath;
    InteractData *m_defaultData;

    void loadBackground();
};

#endif // SCREENVIEW_H