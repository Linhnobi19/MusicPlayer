
#include "SongModel.h"
#include <QDir>
#include <QStringList>
#include <QFileInfoList>
#include <QDebug>
#include <QEventLoop>
#include <QTime>
#include <QImage>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMediaMetaData>
#include <QTimer>

SongModel::SongModel(QObject *parent)
    : QObject{parent}
{
    // addSong("C:/Users/ASUS/Music");

}

QList<Song *> SongModel::playlist() const
{
    return m_playlist;
}

void SongModel::setPlaylist(const QList<Song *> &newPlaylist)
{
    if (m_playlist == newPlaylist)
        return;
    m_playlist = newPlaylist;
    emit playlistChanged();
}

void SongModel::addSong(QString url)
{
    QDir dir(url);
    QStringList filters;
    filters << "*.mp3" << "*.wav" << "*.ogg" << "*.flac";  // format want to find
    dir.setNameFilters(filters);

    // get info of music list
    QFileInfoList fileList = dir.entryInfoList();
    qDebug() << "Number of list " << fileList.size();

    QList<Song*> newPlaylist;

    // add each music info to list
    foreach (const QFileInfo &fileInfo, fileList) {
        QMediaPlayer* player = new QMediaPlayer();

        // Kết nối signal để nhận metadata khi nó sẵn sàng
        QObject::connect(player, &QMediaPlayer::metaDataAvailableChanged, [&newPlaylist, fileInfo, player](bool available) mutable {
            if (available) {
                QString title = player->metaData(QMediaMetaData::Title).toString();
                QString artist = player->metaData(QMediaMetaData::ContributingArtist).toString();
                QString album = player->metaData(QMediaMetaData::AlbumTitle).toString();
                QImage art = player->metaData(QMediaMetaData::CoverArtImage).value<QImage>();
                QImage art2 = player->metaData(QMediaMetaData::ThumbnailImage).value<QImage>();
                QString source = fileInfo.absoluteFilePath();
                // qDebug() << "new source " << source;
                // qDebug() << art;


                if(title.isEmpty()){
                    title = "Unknow";
                }
                if(artist.isEmpty()){
                    artist = "Unknow";
                }
                if(album.isEmpty()){
                    album = "Unknow";
                }

                QString filePath = source.chopped(4) + ".jpg";
                // qDebug() << filePath;
                bool check = art.save(filePath);
                // qDebug() << filePath;
                if(!check){
                    check = art2.save(filePath);
                    if(!check){
                        filePath = "C:/Users/ASUS/Music/default.jpg";
                    }
                }

                // Tạo đối tượng Song và thêm vào danh sách
                Song* song = new Song(title, artist, album, source, filePath);
                // songList.push_back(song);
                newPlaylist.append(song);

                qDebug() << "Added: " << title << " by " << artist;

                player->deleteLater();  // Giải phóng bộ nhớ
            }
        });

        player->setMedia(QUrl::fromLocalFile(fileInfo.absoluteFilePath()));
        player->play();  // Khởi động để lấy metadata
    }

    QEventLoop loop;
    QTimer::singleShot(1000, &loop, &QEventLoop::quit);
    loop.exec();

    qDebug() << "New playlist size " << newPlaylist.size();
    for(int i = 0; i < newPlaylist.size(); i++){
        m_playlist.append(newPlaylist[i]);
    }
    // Kiểm tra xem playlist đã có tệp tin nhạc chưa
    if (m_playlist.isEmpty()) {
        qDebug() << "No audio files were found in the directory.";
        return;
    }
    emit playlistChanged();
}
