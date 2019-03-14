#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>

#include "model/BoxElement.h"

class ListModel : public QAbstractListModel
{
    Q_OBJECT
private:
    QList<BoxElement> m_listModel;
public:
    ListModel();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int,QByteArray> roleNames() const;
public:
    void append(BoxElement element);
    bool update(int idx, BoxElement element);
    bool update(int idx, E_ROLE_LIST_MODEL role, QVariant value);
};

#endif // LISTMODEL_H
