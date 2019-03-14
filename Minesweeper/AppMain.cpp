#include "AppMain.h"
#include <QQmlContext>
#include <QQuickItem>

AppMain::AppMain()
    : m_view(nullptr)
    , m_listModel(nullptr)
{
    m_listModel = new ListModel();
    for (int i = 0; i < 100; i++) {
        BoxElement element;
        m_listModel->append(element);
    }
    m_view = new QQuickView(QUrl("qrc:/main.qml"));
    m_view->show();

    m_view->rootContext()->setContextProperty("appmain", this);
    m_view->rootContext()->setContextProperty("listModel", m_listModel);

    m_view->rootObject()->setProperty("mainSourceLoader", "qrc:/qml/page/MinesweeperPlayer.qml");
}

void AppMain::hmiEvent(int eventId, QString parameter)
{
    qDebug("AppMain::hmiEvent eventId[%d] parameter[%s]", eventId, parameter.toStdString().c_str());
    BoxElement newElement;
    newElement.setValue(5);
    m_listModel->update(eventId, newElement);
}
