#ifndef BOXELEMENT_H
#define BOXELEMENT_H

#include "AppDefine.h"

class BoxElement
{
private:
    int m_value;
    E_BOX_STATUS m_status;
public:
    BoxElement();
public:
    int getValue();
    E_BOX_STATUS getStatus();
    bool isBomb();
    bool isOpen();
    bool isFlag();
public:
    void setValue(int value);
    void setStatus(E_BOX_STATUS status);
};

#endif // BOXELEMENT_H
