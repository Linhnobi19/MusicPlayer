#ifndef SONG_H
#define SONG_H

#include <QObject>

class Song : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged FINAL)
    Q_PROPERTY(QString singer READ singer WRITE setSinger NOTIFY singerChanged FINAL)
    Q_PROPERTY(QString album READ album WRITE setAlbum NOTIFY albumChanged FINAL)
    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged FINAL)
    Q_PROPERTY(QString albumArt READ albumArt WRITE setAlbumArt NOTIFY albumArtChanged FINAL)
public:
    explicit Song(QObject *parent = nullptr);
    Song(QString& title, QString& singer, QString& album, QString& source,
         QString& albumArt, QObject* parent = nullptr);

    QString title() const;
    void setTitle(const QString &newTitle);

    QString singer() const;
    void setSinger(const QString &newSinger);

    QString album() const;
    void setAlbum(const QString &newAlbum);

    QString source() const;
    void setSource(const QString &newSource);

    QString albumArt() const;
    void setAlbumArt(const QString &newAlbumArt);

signals:
    void titleChanged();
    void singerChanged();

    void albumChanged();

    void sourceChanged();

    void albumArtChanged();

private:
    QString m_title;
    QString m_singer;
    QString m_album;
    QString m_source;
    QString m_albumArt;
};

#endif // SONG_H
