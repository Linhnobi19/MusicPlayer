#ifndef MUSICCONTROLLER_H
#define MUSICCONTROLLER_H

#include <QObject>
#include "SongModel.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QStringList>

class MusicController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(SongModel* model READ model WRITE setModel NOTIFY modelChanged FINAL)
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged FINAL)
public:
    explicit MusicController(QObject *parent = nullptr);

    SongModel *model() const;
    void setModel(SongModel *newModel);

    Q_INVOKABLE QString getTime(int value);
    Q_INVOKABLE void next();
    Q_INVOKABLE void prev();
    Q_INVOKABLE void playRandom(int index, QString source = "");
    Q_INVOKABLE void setPlaylist(QString path);
    Q_INVOKABLE void setRandom();
    Q_INVOKABLE void setLoop();

    // for storing info of last song
    Q_INVOKABLE void saveCurrentSong(QString source, int currentTime);
    Q_INVOKABLE void loadCurrentSong();

    Q_INVOKABLE void savePath(QString source);
    Q_INVOKABLE void loadPath();

    Q_INVOKABLE QList<Song*> searchSong(QString name);


    // for searching name of song



signals:
    void modelChanged();
    void currentIndexChanged();
    void changeSong();
    void findSong(int value);

private:
    SongModel *m_model = nullptr;
    QStringList pathSongs;

    void updatePlaylist();
    int m_currentIndex;

public:
    QMediaPlayer* m_player;
    QMediaPlaylist* m_playlist;

    int currentIndex() const;
    void setCurrentIndex(int newCurrentIndex);
};

#endif // MUSICCONTROLLER_H
