#include "ListModel.h"
#include "AppDefine.h"

ListModel::ListModel()
{
}

int ListModel::rowCount(const QModelIndex &parent) const
{
    return m_listModel.count();
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }
    int idx = index.row();
    BoxElement boxElement = m_listModel[idx];
    if (role == E_ROLE_LIST_MODEL::VALUE) {
        return boxElement.getValue();
    } else if (role == E_ROLE_LIST_MODEL::STATUS) {
        return boxElement.getStatus();
    } else if (role == E_ROLE_LIST_MODEL::IS_BOMB) {
        return boxElement.isBomb();
    } else {
        return QVariant();
    }
}

QHash<int, QByteArray> ListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[E_ROLE_LIST_MODEL::VALUE] = "value";
    roles[E_ROLE_LIST_MODEL::STATUS] = "status";
    roles[E_ROLE_LIST_MODEL::IS_BOMB] = "isBomb";
    return roles;
}

void ListModel::append(BoxElement element)
{
    m_listModel.append(element);
}

bool ListModel::update(int idx, BoxElement element)
{
    m_listModel[idx] = element;
    emit dataChanged(index(idx), index(idx));
    return true;
}
