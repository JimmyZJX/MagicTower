#ifndef MAGICOBJECT_H
#define MAGICOBJECT_H

#include "MagicExpression/magicvarient.h"

#include <QHash>
#include <QSet>
#include <QVariant>
#include <QObject>

class MagicObject : QObject
{
    QSet<QString> mClass;

public:
    MagicObject();

    QHash<QString, MagicVarient> property;

    bool inClass(QString);
    bool inClass(QList<QString>);
    void appendClass(QString);

    virtual MagicVarient &operator[](QString);
    virtual const MagicVarient &operator[](QString) const;
    virtual void setProperty(QString, MagicVarient);
};

#endif // MAGICOBJECT_H
