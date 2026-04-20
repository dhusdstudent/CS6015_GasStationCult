#ifndef NAVCLICK_H
#define NAVCLICK_H

#include "clickable.h"
#include <QString>

class GameManager;

// A clickable that changes the current screen.
// Optionally only enabled if a flag is set.
class NavClick : public Clickable
{
public:
    explicit NavClick(int targetScreenId,
                      GameManager *manager,             // Not owned
                      const QString &requiredFlag = QString(),
                      QGraphicsItem *parent = nullptr);

    void onClick() override;
    bool isEnabled() const;

private:
    int m_targetScreenId;
    GameManager *m_manager;             // Aggregated, not owned
    QString m_requiredFlag;             // Empty means always enabled
};

#endif // NAVCLICK_H