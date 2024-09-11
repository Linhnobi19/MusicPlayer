#include "Song.h"

Song::Song(QObject *parent)
    : QObject{parent}
{}

Song::Song(QString &title, QString &singer, QString &album, QString &source, QString &albumArt, QObject *parent)
    : m_title(title), m_singer(singer), m_album(album)
    , m_source(source), m_albumArt(albumArt), QObject{parent}
{

}

QString Song::title() const
{
    return m_title;
}

void Song::setTitle(const QString &newTitle)
{
    if (m_title == newTitle)
        return;
    m_title = newTitle;
    emit titleChanged();
}

QString Song::singer() const
{
    return m_singer;
}

void Song::setSinger(const QString &newSinger)
{
    if (m_singer == newSinger)
        return;
    m_singer = newSinger;
    emit singerChanged();
}

QString Song::album() const
{
    return m_album;
}

void Song::setAlbum(const QString &newAlbum)
{
    if (m_album == newAlbum)
        return;
    m_album = newAlbum;
    emit albumChanged();
}

QString Song::source() const
{
    return m_source;
}

void Song::setSource(const QString &newSource)
{
    if (m_source == newSource)
        return;
    m_source = newSource;
    emit sourceChanged();
}

QString Song::albumArt() const
{
    return m_albumArt;
}

void Song::setAlbumArt(const QString &newAlbumArt)
{
    if (m_albumArt == newAlbumArt)
        return;
    m_albumArt = newAlbumArt;
    emit albumArtChanged();
}
