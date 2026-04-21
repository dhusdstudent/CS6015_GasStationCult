#include "gamemanager.h"
#include "screenview.h"
#include "interactwindow.h"
#include <QGraphicsView>

GameManager::GameManager(QGraphicsView *view, QObject *parent)
    : QObject(parent)
    , m_view(view)
    , m_interactWindow(nullptr)
    , m_currentScreenId(-1)
{
}

GameManager::~GameManager()
{
    qDeleteAll(m_screens);
}

void GameManager::addScreen(ScreenView *screen)
{
    m_screens.append(screen);
}

void GameManager::changeScreen(int id)
{
    if (id < 0 || id >= m_screens.size()) return;
    if (id == m_currentScreenId) return;

    m_currentScreenId = id;
    ScreenView *screen = m_screens[id];

    // Move the InteractWindow into the new scene if it exists
    if (!m_interactWindow) {
        m_interactWindow = new InteractWindow(this);
        m_interactWindow->setPos(200, 300);
    }
    screen->addItem(m_interactWindow);
    m_interactWindow->hide();

    screen->render();
    m_view->setScene(screen);
}

void GameManager::addFlag(const QString &id)
{
    m_flags[id] = true;
    // Re-render current screen so conditional clickables update
    if (m_currentScreenId >= 0)
        m_screens[m_currentScreenId]->render();
}

bool GameManager::getFlag(const QString &id) const
{
    return m_flags.value(id, false);
}

void GameManager::showInteractWindow(InteractData *data)
{
    if (m_interactWindow)
        m_interactWindow->display(data);
}

InteractWindow *GameManager::interactWindow() const
{
    return m_interactWindow;
}