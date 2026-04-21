#include <QApplication>
#include <QGraphicsView>
#include <QFile>
#include "gamemanager.h"
#include "screenview.h"
#include "interactclick.h"
#include "navclick.h"
#include "interactdata.h"
#include "choice.h"
#include "sound.h"

int main(int argc, char** argv){
    QApplication app(argc, argv);

    QGraphicsView view;
    view.setFixedSize(908, 690);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    GameManager manager(&view);

    // --- Build screen 0: exterior of the gas station ---
    auto *narration0 = new InteractData("You roll into the empty parking lot of the gas station, barely making after what you think must be miles of running fumes. Perhaps you're just lucky? But maybe not so much... the gas pump is unpowered. Maybe someone inside can help?");
    narration0->addChoice(new Choice("Go inside", ChoiceType::SCENE_CHANGE, QString("1")));
    narration0->addChoice(new Choice("Just walk away. You've been hearing a lot about \"Haunted Gas Stations\" and don't want to take your chances.", ChoiceType::SCENE_CHANGE, QString("2")));
    auto *screen0 = new ScreenView(":/images/viewExterior.png", &manager, nullptr, narration0);

    // --- Build screen 1: interior --- viewTaquitoRoller
    auto *narration1 = new InteractData("You step into the dimly lit gas station, searching for someone to help you. ");
    narration1->addChoice(new Choice("", ChoiceType::SCENE_CHANGE, QString("3")));
    auto *screen1 = new ScreenView(":/images/viewTaquitoRoller.png", &manager, nullptr, narration1);

    // --- Build screen 2: good ending --- viewRacoons
    auto *narration2 = new InteractData("You turn your back on the gas station and the rest of society as well. The first few days of foraging in the woods are hard living, but you are soon discovered and adopted by a loving family of raccoons. You live a rich life of boundless freedom with them, of which most people would not dare to even dream of\n\n.");
    narration2->addChoice(new Choice("GOOD ENDING 1! Play again", ChoiceType::SCENE_CHANGE, QString("0")));
    auto *screen2 = new ScreenView(":/images/viewRacoons.png", &manager, nullptr, narration2);

    // --- Build Screen 3: talking to cashier --- viewTaquitoWithCultist
    auto *narration3 = new InteractData("A hooded figure appears from the darkness behind the taquito rollers. You explain your troubl");
    narration3->addChoice(new Choice("", ChoiceType::SCENE_CHANGE, QString("")));
    narration3->addChoice(new Choice("", ChoiceType::SCENE_CHANGE, QString("")));
    auto *screen3 = new ScreenView(":/images/viewTaquitoWithCultist.png", &manager, nullptr, narration3);

    // --- Build Screen 4: follow up with Cashier --- viewTaquitoWithCultist
    auto *narration4 = new InteractData("");
    narration4->addChoice(new Choice("", ChoiceType::SCENE_CHANGE, QString("")));
    auto *screen4 = new ScreenView(":/images/viewTaquitoWithCultist.png", &manager, nullptr, narration4);

    // --- Build Screen 5: bad ending --- viewCosmic
    auto *narration5 = new InteractData("");
    narration5->addChoice(new Choice("", ChoiceType::SCENE_CHANGE, QString("")));
    narration5->addChoice(new Choice("", ChoiceType::SCENE_CHANGE, QString("")));
    auto *screen5 = new ScreenView(":/images/viewCosmic.png", &manager, nullptr, narration5);

    // --- Build Screen 6: slurpy --- viewSlurpyAisle
    auto *narration6 = new InteractData("");
    narration6->addChoice(new Choice("", ChoiceType::SCENE_CHANGE, QString("")));
    narration6->addChoice(new Choice("", ChoiceType::SCENE_CHANGE, QString("")));
    auto *screen6 = new ScreenView(":/images/viewSlurpyAisle.png", &manager, nullptr, narration6);

    // --- Build Screen 7: open door --- viewEmployeeDoorOpen
    auto *narration7 = new InteractData("");
    narration7->addChoice(new Choice("", ChoiceType::SCENE_CHANGE, QString("")));
    auto *screen7 = new ScreenView(":/images/viewEmployeeDoorOpen.png", &manager, nullptr, narration7);

    // --- Build Screen 8: bad ending --- viewCosmic
    auto *narration8 = new InteractData("");
    narration8->addChoice(new Choice("", ChoiceType::SCENE_CHANGE, QString("")));
    narration8->addChoice(new Choice("", ChoiceType::SCENE_CHANGE, QString("")));
    auto *screen8 = new ScreenView(":/images/viewCosmic.png", &manager, nullptr, narration8);

    // --- Build Screen 9: in front of the door - viewToiletDoor
    auto *narration9 = new InteractData("");
    narration9->addChoice(new Choice("", ChoiceType::SCENE_CHANGE, QString("")));
    auto *screen9 = new ScreenView(":/images/viewToiletDoor.png", &manager, nullptr, narration9);

    // --- Build Screen 10: open door - viewToiletDoorOpen
    auto *narration10 = new InteractData("");
    narration10->addChoice(new Choice("", ChoiceType::SCENE_CHANGE, QString("")));
    narration10->addChoice(new Choice("", ChoiceType::SCENE_CHANGE, QString("")));
    auto *screen10 = new ScreenView(":/images/viewToiletDoorOpen.png", &manager, nullptr, narration10);

    // --- Good End: Back out front you get away - viewExterior
    auto *narration11 = new InteractData("");
    narration11->addChoice(new Choice("", ChoiceType::SCENE_CHANGE, QString("")));
    narration11->addChoice(new Choice("", ChoiceType::SCENE_CHANGE, QString("")));
    auto *screen11 = new ScreenView(":/images/viewExterior.png", &manager, nullptr, narration11);

    manager.addScreen(screen0);  // id = 0
    manager.addScreen(screen1);  // id = 1
    manager.addScreen(screen2);  // id = 2
    manager.addScreen(screen3);  // id = 3
    manager.addScreen(screen4);  // id = 4
    manager.addScreen(screen5);  // id = 5
    manager.addScreen(screen6);  // id = 6
    manager.addScreen(screen7);  // id = 7
    manager.addScreen(screen8);  // id = 8
    manager.addScreen(screen9);  // id = 9
    manager.addScreen(screen10); // id = 10
    manager.addScreen(screen11); // id = 11
    manager.changeScreen(0);     // Start on exterior

    Sound sound;
    sound.playSound();

    view.show();
    return app.exec();
}
