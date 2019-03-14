#include "BoxElement.h"

BoxElement::BoxElement()
    : m_value(0)
    , m_status(E_BOX_STATUS::CLOSE)
{

}

int BoxElement::getValue()
{
    return m_value;
}

E_BOX_STATUS BoxElement::getStatus()
{
    return m_status;
}

bool BoxElement::isBomb()
{
    bool result = false;
    if (m_value == -1) {
        result = true;
    }
    return result;
}

bool BoxElement::isOpen()
{
    if (m_status == E_BOX_STATUS::OPEN) {
        return true;
    }
    return false;
}

bool BoxElement::isFlag()
{
    if (m_status == E_BOX_STATUS::FLAG){
        return true;
    }
    return false;
}

void BoxElement::setValue(int value)
{
    m_value = value;
}

void BoxElement::setStatus(E_BOX_STATUS status)
{
    m_status = status;
}
