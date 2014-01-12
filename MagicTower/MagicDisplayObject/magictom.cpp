#include "magictom.h"
#include "magickey.h"

#include <QBitmap>
#include <QDebug>

QString Pix_string[4][3] = {  {":/images/Tom_face1", ":/images/Tom_face2", ":/images/Tom_face"},
                              {":/images/Tom_left1", ":/images/Tom_left2", ":/images/Tom_left"},
                              {":/images/Tom_back1", ":/images/Tom_back2", ":/images/Tom_back"},
                              {":/images/Tom_right1", ":/images/Tom_right2", ":/images/Tom_right"}};

MagicTom::MagicTom(int x, int y, int level, MagicMap *parent)
    : MagicDisplayObject(x, y, level, parent)
{
    for(int i=0; i<4; i++)
        for(int j=0; j<3; j++)
            Pix[i][j] = new QPixmap(Pix_string[i][j]);

    MagicKey *p;
    for(int i = 0; i < 100; i++)
    {
        p = new MagicKey(5, 5, 0, parent, 0);
        p->property["enabled"] = 0;
        backupKey0.push_back(p);
        p = new MagicKey(5, 5, 0, parent, 1);
        p->property["enabled"] = 0;
        backupKey1.push_back(p);
        p = new MagicKey(5, 5, 0, parent, 2);
        p->property["enabled"] = 0;
        backupKey2.push_back(p);
    }

    pix = Pix[0][2];

    property["label"] = "tom";
    property["attack"] = 50;
    property["defend"] = 50;
    property["health"] = 500;
    property["exp"] = 0;
    property["money"] = 0;
    property["id"] = "";
    property["range"] = 0;

    qDebug() <<"Tom: "<< property["attack"].getInt() << property["defend"].getInt() << property["health"].getInt();
    qDebug() <<"Tom: "<< property["label"].getString() << property["level"].getInt() << property["id"].getString();
}

void MagicTom::paint(QPainter *painter)
{
    painter->drawPixmap(x, y, *pix);
}

bool MagicTom::move(MagicMap *)
{
    return true;
}

void MagicTom::setProperty(QString propertyName, MagicVarient propertyValue)
{
    if (propertyName == "add_K")
    {
        switch (propertyValue.getInt())
        {
        case 0:
            backupKey0.takeFirst()->setProperty("picked", 1);
            break;
        case 1:
            backupKey1.takeFirst()->setProperty("picked", 1);
            break;
        case 2:
            backupKey2.takeFirst()->setProperty("picked", 1);
            break;
        }
        return;
    }
    if (propertyName == "level" && propertyValue.getInt() > property["range"].getInt())
        property["range"] = propertyValue.getInt();
    MagicDisplayObject::setProperty(propertyName, propertyValue);
}

void MagicTom::changePic(int direction, int duration)
{
    if (duration > 0)
        pix = Pix[direction][(duration / 4) % 2];
    else
        pix = Pix[direction][2];
}


bool MagicTom::haveInventory(QString label)
{
    for (auto i = inventory.begin(); i != inventory.end(); i++)
        if ( ((**i)["label"] == MagicVarient(label)).isTrue() )
            return true;
    return false;
}

bool MagicTom::consumeInventory(QString label)
{
    for (auto i = inventory.begin(); i != inventory.end(); i++)
        if ( ((**i)["label"] == MagicVarient(label)).isTrue() )
        {
            i = inventory.erase(i);
            return true;
        }
    return false;
}

bool MagicTom::consumeInventory(QString label, int color)
{
    for (auto i = inventory.begin(); i != inventory.end(); i++)
        if ( ((**i)["label"] == MagicVarient(label)).isTrue() &&
             ((**i)["color"] == MagicVarient(color)).isTrue() )
        {
            i = inventory.erase(i);
            return true;
        }
    return false;
}
