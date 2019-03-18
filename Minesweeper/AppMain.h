#ifndef APPMAIN_H
#define APPMAIN_H

#include <QObject>
#include <QQuickView>
#include "model/ListModel.h"
#include "model/BoxElement.h"

class AppMain : public QObject
{
    Q_OBJECT
private:
    QQuickView *m_view;
    ListModel *m_listModel;
    int m_widthCount;
    int m_heightCount;
    int m_bombs;
public:
    AppMain();
public:
    Q_INVOKABLE void hmiEvent(int eventId, QString parameter);

private:
    void creatMap(int m, int n, int number);
    void startGame();
};

#endif // APPMAIN_H
