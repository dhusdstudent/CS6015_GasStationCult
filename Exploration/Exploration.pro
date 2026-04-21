HEADERS += \
    choice.h \
    choiceitem.h \
    clickable.h \
    gamemanager.h \
    interactclick.h \
    interactdata.h \
    interactwindow.h \
    keyitem.h \
    profile.h \
    signinform.h \
    navclick.h \
    screenview.h \
    sound.h
 #   movearrow.h \
 #   keyitem.h \
  #  viewpoint.h \
 #   item.h


SOURCES += \
    choice.cpp \
    choiceitem.cpp \
    clickable.cpp \
    gamemanager.cpp \
    interactclick.cpp \
    interactdata.cpp \
    interactwindow.cpp \
    main.cpp \
    profile.cpp \
    signinform.cpp \
    navclick.cpp \
    screenview.cpp \
    sound.cpp
    # viewpoint.cpp \
    # keyitem.cpp \
    # item.cpp \
    # movearrow.cpp

QT += core gui widgets multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RESOURCES += \
    images.qrc

DISTFILES +=