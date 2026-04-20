#include "navclick.h"
#include "gamemanager.h"

NavClick::NavClick(int targetScreenId,
                   GameManager *manager,
                   const QString &requiredFlag,
                   QGraphicsItem *parent)
    : Clickable(parent)
    , m_targetScreenId(targetScreenId)
    , m_manager(manager)
    , m_requiredFlag(requiredFlag)
{
}

void NavClick::onClick()
{
    if (isEnabled() && m_manager)
        m_manager->changeScreen(m_targetScreenId);
}

bool NavClick::isEnabled() const
{
    if (m_requiredFlag.isEmpty())
        return true;
    return m_manager && m_manager->getFlag(m_requiredFlag);
}