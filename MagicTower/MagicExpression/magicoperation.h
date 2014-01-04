#ifndef MAGICOPERATION_H
#define MAGICOPERATION_H

#include "magicoperand.h"

class MagicOperation : public MagicOperand
{
    QString mOperator;
    MagicOperand *operand[2];

public:
    MagicOperation(MagicOperand *, MagicOperand *, QString);
    MagicOperation(MagicOperand *, QString);
    virtual MagicVarient getValue(MagicMap *);
};

#endif // MAGICOPERATION_H
