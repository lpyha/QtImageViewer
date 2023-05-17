#include "mousescene.h"

MouseScene::MouseScene(QObject *parent)
    : QGraphicsScene{parent}
{

}

void MouseScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    cout << event->scenePos().x() << ", " << event->scenePos().y() << endl;
}
