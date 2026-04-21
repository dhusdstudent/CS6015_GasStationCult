#include "sound.h"
#include <QMediaPlayer>
#include <QAudioOutput>

Sound::Sound(QObject * parent): QObject(parent) {

    musicPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);

    musicPlayer->setAudioOutput(audioOutput);

    audioOutput->setVolume(0.5);
    musicPlayer->setSource(QUrl::fromLocalFile("C:/images/Ambient.wav"));

    loopSound();
}

////////////////////MAKES SOUND PLAY ON REPEAT////////////////////////

void Sound::loopSound(){
    connect(musicPlayer, &QMediaPlayer::mediaStatusChanged, this,
        [=](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia){
            musicPlayer->setPosition(0);
            musicPlayer->play();
        }
    });
}

////////////////////BASIC CONTROLS////////////////////////

void Sound::playSound(){
    musicPlayer->play();
}

void Sound::stopSound(){
    musicPlayer->stop();
}

void Sound::setVolume(float volume){
    audioOutput->setVolume(volume);
}

