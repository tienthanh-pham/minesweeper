#include "AppMain.h"
#include "AppDefine.h"
#include <QQmlContext>
#include <QQuickItem>

AppMain::AppMain()
    : m_view(nullptr)
    , m_listModel(nullptr)
{
    m_listModel = new ListModel();

    creatMap(10, 10, 10);

    m_view = new QQuickView(QUrl("qrc:/main.qml"));
    m_view->show();

    m_view->rootContext()->setContextProperty("appmain", this);
    m_view->rootContext()->setContextProperty("listModel", m_listModel);

    m_view->rootObject()->setProperty("mainSourceLoader", "qrc:/qml/page/MinesweeperPlayer.qml");
}

void AppMain::hmiEvent(int eventId, QString parameter)
{
    qDebug("AppMain::hmiEvent eventId[%d] parameter[%s]", eventId, parameter.toStdString().c_str());
    switch (eventId) {
    case E_HMI_EVENT::BOX_RIGHT_CLICK:
        m_listModel->update(parameter.split(",").at(0).toInt(), E_ROLE_LIST_MODEL::STATUS,
                            parameter.split(",").at(1).toInt() ? E_BOX_STATUS::FLAG : E_BOX_STATUS::CLOSE);
        break;
    case E_HMI_EVENT::BOX_LEFT_CLICK:
        m_listModel->update(parameter.toInt(), E_ROLE_LIST_MODEL::STATUS, E_BOX_STATUS::OPEN);
        break;
    default:
        break;
    }
}

void AppMain::creatMap(int m, int n, int number)
{
    QList<int>model;
    for (int i = 0; i < m * n; i++){
        model.append(0);
    }
    int BOMB = -1;
    int i = 0;

    while (number != 0) {
        i = floor(rand() % (m * n));
        if (model[i] != BOMB) {
            model[i] = BOMB;
            bool top = (floor(i/m) == 0);
            bool bottom = (floor(i/m) == n-1);
            bool left = (i%m == 0);
            bool right = (i%m == m-1);

            if (!left && model[i-1] != BOMB) model[i-1]++;
            if (!right && model[i+1] != BOMB) model[i+1]++;
            if (!top && model[i-m] != BOMB) model[i-m]++;
            if (!bottom && model[i+m] != BOMB) model[i+m]++;

            if (!left && !top && model[i-m-1] != BOMB) model[i-m-1]++;
            if (!right && !top && model[i-m+1] != BOMB) model[i-m+1]++;
            if (!bottom && !left && model[i+m-1] != BOMB) model[i+m-1]++;
            if (!bottom && !right && model[i+m+1] != BOMB) model[i+m+1]++;
            number--;
        }
    }

    foreach (int value, model){
        BoxElement element;
        element.setValue(value);
        m_listModel->append(element);
    }
}
