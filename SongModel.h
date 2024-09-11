#ifndef SONGMODEL_H
#define SONGMODEL_H

#include <QObject>
#include <QList>
#include "Song.h"

class SongModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<Song*> playlist READ playlist WRITE setPlaylist NOTIFY playlistChanged FINAL)

public:
    explicit SongModel(QObject *parent = nullptr);

    QList<Song *> playlist() const;
    void setPlaylist(const QList<Song *> &newPlaylist);

    void addSong(QString url);

signals:
    void playlistChanged();
private:
    QList<Song *> m_playlist;
};

#endif // SONGMODEL_H
