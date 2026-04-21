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
    auto *narration0 = new InteractData("You roll into the empty parking lot of the gas station, barely making after what you think must be miles of running fumes. Perhaps you're just lucky? But maybe not so much... the gas pump is unpowered. Maybe someone inside can help?\n\n");
    narration0->addChoice(new Choice("Go inside", ChoiceType::SCENE_CHANGE, QString("1")));
    narration0->addChoice(new Choice("Just walk away. You've been hearing a lot about \"Haunted Gas Stations\" and don't want to take your chances.", ChoiceType::SCENE_CHANGE, QString("2")));
    auto *screen0 = new ScreenView(":/images/viewExterior.png", &manager, nullptr, narration0);

    // --- Build screen 1: interior --- viewTaquitoRoller
    auto *narration1 = new InteractData("You step into the dimly lit gas station, searching for someone to help you.\n\nYou see a bell labeled \'Ring for Service\'. It stained by a dark substance... oil? Your gaze is drawn in by the glassy sheen and for a moment you feel like you are staring into the stars.\n\n");
    narration1->addChoice(new Choice("Ring the bell.", ChoiceType::SCENE_CHANGE, QString("3")));
    auto *screen1 = new ScreenView(":/images/viewTaquitoRoller.png", &manager, nullptr, narration1);

    // --- Build screen 2: good ending --- viewRacoons
    auto *narration2 = new InteractData("You turn your back on the gas station and the rest of society as well. The first few days of foraging in the woods are hard living, but you are soon discovered and adopted by a loving family of raccoons. You live a rich life of boundless freedom with them, of which most people would not dare to even dream of.\n\n");
    narration2->addChoice(new Choice("YOU'VE UNLOCKED \"RACOON ENDING (GOOD)\"!\nPlay again", ChoiceType::SCENE_CHANGE, QString("0")));
    auto *screen2 = new ScreenView(":/images/viewRacoons.png", &manager, nullptr, narration2);

    // --- Build Screen 3: talking to cashier --- viewTaquitoWithCultist
    auto *narration3 = new InteractData("A hooded figure appears from the darkness behind the taquito rollers. You explain your trouble with the gas pump.\n\"I'm so sorry, but it's members only hours for our gas station pump. I'll turn it on as soon as you sign up.\"\n\n");
    narration3->addChoice(new Choice("What can another membership hurt? Sign up.", ChoiceType::SCENE_CHANGE, QString("5")));
    narration3->addChoice(new Choice("Read the fine print.", ChoiceType::SCENE_CHANGE, QString("4")));
    auto *screen3 = new ScreenView(":/images/viewTaquitoWithCultist.png", &manager, nullptr, narration3);

    // --- Build Screen 4: follow up with Cashier --- viewTaquitoWithCultist
    auto *narration4 = new InteractData("You notice the fine print of the agreement would sign away the rights to your soul to the shell corporation running this gas station. Uh oh... you're already signed those rights away when joining your grocery store's membership program.\n\nThe figure apologizes, and directs you to the nearby slurpy machine for a complimentary treat.");
    narration4->addChoice(new Choice("Slurpy? Yum.", ChoiceType::SCENE_CHANGE, QString("6")));
    auto *screen4 = new ScreenView(":/images/viewTaquitoWithCultist.png", &manager, nullptr, narration4);

    // --- Build Screen 5: bad ending --- viewCosmic
    auto *narration5 = new InteractData("Your vision fades, and awake outside of time in a space beyond space. You see an entity that your tries and fails to represent in your mind as a hodgepodge of cultural and everyday figures. Is this a lovecraftian entity that the hooded guy you met worships? I guess so.\n\n");
    narration5->addChoice(new Choice("YOU'VE UNLOCKED \"COSMIC DISSOLUTION ENDING (AMBIGUOUS)\"\nPlay Again" , ChoiceType::SCENE_CHANGE, QString("0")));
    auto *screen5 = new ScreenView(":/images/viewCosmic.png", &manager, nullptr, narration5);

    // --- Build Screen 6: slurpy --- viewSlurpyAisle
    auto *narration6 = new InteractData("A slurpy would be nice right about now. What flavor? They've got... \"Diesel-icious\", \"Propane Colada\"? \"British Petroleum Blast\"? There seems to be a theme here...\nThey also have grape.");
    narration6->addChoice(new Choice("Hmm, what's behind that door?", ChoiceType::SCENE_CHANGE, QString("7")));
    narration6->addChoice(new Choice("Propane Colada sounds nice.", ChoiceType::SCENE_CHANGE, QString("5")));
    auto *screen6 = new ScreenView(":/images/viewSlurpyAisle.png", &manager, nullptr, narration6);

    // --- Build Screen 7: open door --- viewEmployeeDoorOpen
    auto *narration7 = new InteractData("You notice an employee door. You push it open... what's back there?");
    narration7->addChoice(new Choice("Open it...", ChoiceType::SCENE_CHANGE, QString("8")));
    auto *screen7 = new ScreenView(":/images/viewEmployeeDoorOpen.png", &manager, nullptr, narration7);

    // --- Build Screen 8: in front of the door - viewToiletDoor
    auto *narration8 = new InteractData("An employee bathroom? Something deep within you compels you forward.");
    narration8->addChoice(new Choice("Open the door", ChoiceType::SCENE_CHANGE, QString("9")));
    auto *screen8 = new ScreenView(":/images/viewToiletDoor.png", &manager, nullptr, narration8);

    // --- Build Screen 9: open door - viewToiletDoorOpen
    auto *narration9 = new InteractData("Within the bathroom you find spare robes like that cultist guy had. They fit you great.\nYou walk back into gas station proper.");
    narration9->addChoice(new Choice("Ask the gas station attendent to turn the pump on.", ChoiceType::SCENE_CHANGE, QString("10")));
    auto *screen9 = new ScreenView(":/images/viewToiletDoorOpen.png", &manager, nullptr, narration9);

    // --- Good End: Back out front you get away - viewExterior
    auto *narration10 = new InteractData("He does! He thinks you're a cultist and doesn't try to trick you into communing with his dark god!\nYou fill up with gas and are on your way. Phew! That could have gone badly.\n");
    narration10->addChoice(new Choice("YOU'VE UNLOCKED \"HAUNTING ESCAPE ENDING (GOOD)\"\nPlay Again", ChoiceType::SCENE_CHANGE, QString("0")));
    auto *screen10 = new ScreenView(":/images/viewExterior.png", &manager, nullptr, narration10);

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
    manager.changeScreen(0);     // Start on exterior

    Sound sound;
    sound.playSound();

    view.show();
    return app.exec();
}
