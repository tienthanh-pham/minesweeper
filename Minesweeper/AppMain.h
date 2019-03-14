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
public:
    AppMain();
public:
    Q_INVOKABLE void hmiEvent(int eventId, QString parameter);
};

#endif // APPMAIN_H
