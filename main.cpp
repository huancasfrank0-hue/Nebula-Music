#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include "player.h"

int main(int argc, char *argv[])
{
    // Configuración para que se vea bien en pantallas HighDPI
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);

    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon::fromTheme("multimedia-audio-player"));
    app.setOrganizationName("NebulaOS");
    app.setApplicationName("NebulaTahoe");

    Player player;
    QQmlApplicationEngine engine;

    // Inyectamos el C++ al QML como "Backend"
    engine.rootContext()->setContextProperty("Backend", &player);

    // NUEVA LÓGICA: Ahora carga desde el sistema de recursos interno (qrc)
    const QUrl url(QStringLiteral("qrc:/Main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
