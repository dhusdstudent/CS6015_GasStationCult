#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include <QList>
#include <QMap>
#include <QString>
#include "interactdata.h"

class ScreenView;
class InteractWindow;
class QGraphicsView;

class GameManager : public QObject
{
    Q_OBJECT
public:
    explicit GameManager(QGraphicsView *view, QObject *parent = nullptr);
    ~GameManager();

    // Screen management
    void addScreen(ScreenView *screen);         // Takes ownership
    void changeScreen(int id);

    // Flag management
    void addFlag(const QString &id);
    bool getFlag(const QString &id) const;

    // Called by InteractClick to show the window
    void showInteractWindow(InteractData *data);

    InteractWindow *interactWindow() const;

private:
    QGraphicsView *m_view;                      // Not owned
    QList<ScreenView*> m_screens;               // Owned
    QMap<QString, bool> m_flags;
    InteractWindow *m_interactWindow;           // Owned by the current scene
    int m_currentScreenId;
};

#endif // GAMEMANAGER_H