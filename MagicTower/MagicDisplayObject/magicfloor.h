#ifndef MAGICFLOOR_H
#define MAGICFLOOR_H

#include "magicdisplayobject.h"

class MagicFloor : public MagicDisplayObject
{

public:
    QPixmap *pix;
    MagicFloor(int, int);
    virtual void paint(QPainter *);
    virtual bool move(MagicMap *);
};

#endif // MAGICFLOOR_H
