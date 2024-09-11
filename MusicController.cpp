#include "MusicController.h"
#include <QUrl>
#include <QDir>
#include <QDebug>
#include <QTime>
#include <QSettings>


MusicController::MusicController(QObject *parent)
    : QObject{parent}, m_currentIndex(0)
{

    m_player = new QMediaPlayer();
    m_playlist = new QMediaPlaylist();

    m_player->setPlaylist(m_playlist);
    m_model = new SongModel();

    loadPath();
    for(int i = 0; i < m_model->playlist().count(); i++){
        m_playlist->addMedia(QUrl(m_model->playlist()[i]->source()));
    }

    if(m_playlist->mediaCount() != 0) {
        m_playlist->setCurrentIndex(m_currentIndex);
        m_player->setMedia(QUrl(m_model->playlist()[m_playlist->currentIndex()]->source()));

        loadCurrentSong();
    }

    connect(m_player, &QMediaPlayer::mediaStatusChanged, this, [&](){
        if(m_player->mediaStatus() == QMediaPlayer::EndOfMedia){
            if(m_playlist->playbackMode() == QMediaPlaylist::Sequential){
                if(m_currentIndex == m_model->playlist().count() - 1){
                    m_currentIndex = 0;
                }
                else {
                    m_currentIndex++;
                }
                qDebug() << "index " << m_currentIndex;
                m_playlist->setCurrentIndex(m_currentIndex);
                m_player->setMedia(QUrl(m_model->playlist()[m_currentIndex]->source()));
                m_player->play();
                emit currentIndexChanged();
                // this->playRandom(m_currentIndex);
                emit changeSong();
            }
            // else if()

            if(m_playlist->playbackMode() == QMediaPlaylist::Loop){
                m_player->stop();
                m_player->play();
            }

            if(m_playlist->playbackMode() == QMediaPlaylist::Random){
                this->playRandom(-1);
                emit changeSong();
            }
        }
    });
}

SongModel *MusicController::model() const
{
    return m_model;
}

void MusicController::setModel(SongModel *newModel)
{
    if (m_model == newModel)
        return;
    m_model = newModel;
    emit modelChanged();
}

QString MusicController::getTime(int currentInfo)
{
    QString tStr = "00:00";
    currentInfo = currentInfo/1000;
    qint64 duration = m_player->duration()/1000;    // use for fomat time
    if(duration || currentInfo){
        // set up h, m, s, ms for time and h must in range 0-23,...
        QTime currentTime((currentInfo / 3600) % 24, (currentInfo / 60) % 60
                          , currentInfo % 60, (currentInfo * 1000) % 1000);

        QString format = "mm:ss";
        if(duration > 3600){
            format = "hh::mm:ss";
        }
        tStr = currentTime.toString(format);
    }
    return tStr;
}

void MusicController::next()
{
    m_player->stop();
    if(m_currentIndex == m_model->playlist().count() - 1){
        m_currentIndex = 0;
    }
    else {
        m_currentIndex++;
    }
    m_playlist->setCurrentIndex(m_currentIndex);
    m_player->setMedia(QUrl(m_model->playlist()[m_currentIndex]->source()));
    m_player->play();
    currentIndexChanged();
    changeSong();
}

void MusicController::prev()
{
    m_player->stop();
    if(m_currentIndex == 0){
        m_currentIndex = m_model->playlist().count() - 1;
    }
    else {
        m_currentIndex--;
    }
    m_playlist->setCurrentIndex(m_currentIndex);
    m_player->setMedia(QUrl(m_model->playlist()[m_currentIndex]->source()));
    m_player->play();
    currentIndexChanged();
    changeSong();
}


void MusicController::playRandom(int index, QString source)
{
    if(!source.isEmpty()){
        int count = m_model->playlist().count();
        for(int i = 0; i < count / 2; i++){
            if(source == m_model->playlist()[i]->source()){
                index = i;
                break;
            }
            if(source == m_model->playlist()[count - 1 - i]->source()){
                index = count - 1 - i;
            }
        }
    }
    else if(index < 0 || index > m_model->playlist().count() - 1){
        do {
            index = rand() % m_model->playlist().count();
        } while (index == m_currentIndex);
    }
    m_player->stop();
    m_currentIndex = index;
    m_playlist->setCurrentIndex(m_currentIndex);
    m_player->setMedia(QUrl(m_model->playlist()[index]->source()));
    m_player->play();
    changeSong();
}

void MusicController::setPlaylist(QString path)
{
    m_model->addSong(path);
    updatePlaylist();
}

void MusicController::setRandom()
{
    m_playlist->setPlaybackMode(QMediaPlaylist::Random);
}

void MusicController::setLoop()
{
    m_playlist->setPlaybackMode(QMediaPlaylist::Loop);
}

void MusicController::saveCurrentSong(QString source, int currentTime)
{
    QSettings setting("Linhnobi", "MusicPlayer");

    setting.setValue("currentSong/source", source);
    setting.setValue("currentSong/time", currentTime);
}

void MusicController::loadCurrentSong()
{
    QSettings setting("Linhnobi", "MusicPlayer");
    QString str = setting.value("currentSong/source", "").toString();
    int time = setting.value("currentSong/time", 0).toInt();

    qDebug() << "Stored source is " << str;

    for(int i = 0; i < m_model->playlist().count(); i++){
        if(str == m_model->playlist()[i]->source()){
            m_player->setMedia(QUrl(str));
            m_player->setPosition(time);
            m_player->positionChanged(time);
            m_currentIndex = i;
            qDebug() << "new index is " << m_currentIndex;
            currentIndexChanged();
            return;
        }
    }
}

void MusicController::savePath(QString source)
{
    QSettings setting("Linhnobi", "MusicPlayer");

    if(!pathSongs.contains(source)){
        pathSongs << source;
        setting.setValue("PathFolder", pathSongs);
        qDebug() << "add path " << source;
    }
}

void MusicController::loadPath()
{
    QSettings setting("Linhnobi", "MusicPlayer");
    pathSongs = setting.value("PathFolder", "").toStringList();
    qDebug() << "Path song " << pathSongs;

    if(!pathSongs.isEmpty()){
        qDebug() << "Come here ";
        for(int i = 0; i < pathSongs.count(); i++){
            setPlaylist(pathSongs[i]);
        }

    }
}

QList<Song *> MusicController::searchSong(QString name)
{

    if(name.isEmpty()){
        emit findSong(m_currentIndex);
        return m_model->playlist();
    }
    else {
        QList<Song*> list;
        int index = -1;
        for (auto song : m_model->playlist()) {
            if(song->album().contains(name, Qt::CaseInsensitive) ||
                song->title().contains(name, Qt::CaseInsensitive) ||
                song->singer().contains(name, Qt::CaseInsensitive)){
                list.append(song);
                if(song->source() == m_model->playlist()[m_currentIndex]->source()){
                    index = list.count() - 1;
                }
            }
        }
        emit findSong(index);
        return list;
    }
}

void MusicController::updatePlaylist()
{
    m_playlist->clear();
    for (int var = 0; var < m_model->playlist().count(); ++var) {
        m_playlist->addMedia(QUrl(m_model->playlist()[var]->source()));
    }
    m_playlist->setCurrentIndex(m_currentIndex);
    m_player->setMedia(QUrl(m_model->playlist()[m_currentIndex]->source()));
}

int MusicController::currentIndex() const
{
    return m_currentIndex;
}

void MusicController::setCurrentIndex(int newCurrentIndex)
{
    if (m_currentIndex == newCurrentIndex)
        return;
    m_currentIndex = newCurrentIndex;
    emit currentIndexChanged();
}
