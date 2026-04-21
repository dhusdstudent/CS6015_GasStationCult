#ifndef SOUND_H
#define SOUND_H

#include <QMediaPlayer>
#include <QAudioOutput>

class Sound : public QObject
{
public:
    explicit Sound(QObject * parent = nullptr);

    void playSound();
    void stopSound();
    void setVolume(float volume);

private:
    QMediaPlayer *musicPlayer;
    QAudioOutput *audioOutput;

    void loopSound();
};

#endif // SOUND_H
