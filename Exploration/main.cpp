#include <QApplication>
#include <QGraphicsView>
#include "gamemanager.h"
#include "screenview.h"
#include "interactclick.h"
#include "navclick.h"
#include "interactdata.h"
#include "choice.h"

int main(int argc, char** argv){
    QApplication app(argc, argv);

    QGraphicsView view;
    view.setFixedSize(908, 510);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    GameManager manager(&view);

    // --- Build screen 0: exterior of the gas station ---
    auto *screen0 = new ScreenView(":/images/exterior.jpg", &manager);

    // An interactable object: old pump
    auto *pumpData = new InteractData("An old rusted pump. The handle feels sticky.");
    pumpData->addChoice(new Choice("Take a closer look", ChoiceType::FLAG, "pump_examined"));
    pumpData->addChoice(new Choice("Leave it alone",     ChoiceType::CLOSE));

    auto *pumpClick = new InteractClick(pumpData, manager.interactWindow());
    pumpClick->setPixmap(QPixmap(":/images/pump_hitbox.png"));
    screen0->addClickable(pumpClick, 120, 300);

    // A nav arrow to go inside
    auto *doorNav = new NavClick(1, &manager);
    doorNav->setPixmap(QPixmap(":/images/arrow_right.png"));
    screen0->addClickable(doorNav, 800, 200);

    // --- Build screen 1: interior ---
    auto *screen1 = new ScreenView(":/images/interior.jpg", &manager);
    auto *backNav = new NavClick(0, &manager);
    backNav->setPixmap(QPixmap(":/images/arrow_left.png"));
    screen1->addClickable(backNav, 20, 200);

    manager.addScreen(screen0);  // id = 0
    manager.addScreen(screen1);  // id = 1
    manager.changeScreen(0);     // Start on exterior

    view.show();
    return app.exec();
}