#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "SongModel.h"
#include <MusicController.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // qDebug() << control->playlistmodel->getSong(0)->art();

    // SongModel* model = new SongModel();
    // engine.rootContext()->setContextProperty("modelList", model);

    MusicController* controller = new MusicController();
    engine.rootContext()->setContextProperty("controller", controller);
    engine.rootContext()->setContextProperty("player", controller->m_player);
    engine.rootContext()->setContextProperty("playlist", controller->m_playlist);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
