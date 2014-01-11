
#ifndef WIDGET_H
#define WIDGET_H

#include "magicmap.h"

#include <QWidget>
#include <QString>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent);
    void keyPressEvent(QKeyEvent *);
    MagicMap *getMap();
    void loadMap(QString);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event);

private:
    MagicMap *mMap;
    QString mapToLoad;
};

#endif
