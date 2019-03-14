#ifndef APPDEFINE_H
#define APPDEFINE_H

enum E_BOX_STATUS {
    CLOSE = 0,
    OPEN,
    FLAG
};

enum E_ROLE_LIST_MODEL {
    VALUE = 0,
    STATUS,
    IS_BOMB,
    IS_OPEN,
    IS_FLAG
};

enum E_HMI_EVENT {
    BOX_RIGHT_CLICK = 0,
    BOX_LEFT_CLICK
};


#endif // APPDEFINE_H
