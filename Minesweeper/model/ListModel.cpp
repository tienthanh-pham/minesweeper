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
    } else if (role == E_ROLE_LIST_MODEL::IS_OPEN) {
        return boxElement.isOpen();
    } else if (role == E_ROLE_LIST_MODEL::IS_FLAG) {
        return boxElement.isFlag();
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
    roles[E_ROLE_LIST_MODEL::IS_OPEN] = "isOpen";
    roles[E_ROLE_LIST_MODEL::IS_FLAG] = "isFlag";
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

bool ListModel::update(int idx, E_ROLE_LIST_MODEL role, QVariant value)
{
    switch (role) {
    case E_ROLE_LIST_MODEL::VALUE:
        m_listModel[idx].setValue(value.toInt());
        break;
    case E_ROLE_LIST_MODEL::STATUS:
        m_listModel[idx].setStatus(static_cast<E_BOX_STATUS>(value.toInt()));
    }
    emit dataChanged(index(idx), index(idx));
    return true;
}

void ListModel::clear()
{
    m_listModel.clear();
}
