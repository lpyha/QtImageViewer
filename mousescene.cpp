#include "mousescene.h"

MouseScene::MouseScene(QObject *parent)
    : QGraphicsScene{parent}
{

}

void MouseScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_button = event->button();
    if (m_button == Qt::RightButton){
        cout << "RightButtonPressed" << endl;
    }else if (m_button == Qt::LeftButton){
        cout << "LeftButtonPressed" << endl;
        m_pressPoint = new QPoint(event->scenePos().x(), event->scenePos().y());
    }else{
        cout << "UnknownButtonPressed" << endl;
    }
    cout << m_pressPoint->x() << ", " << m_pressPoint->y() << endl;
}

void MouseScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_button = event->button();
    if (m_button == Qt::RightButton){
        cout << "RightButtonReleased" << endl;
    }else if (m_button == Qt::LeftButton){
        cout << "LeftButtonReleased" << endl;
        m_releasePoint = new QPoint(event->scenePos().x(), event->scenePos().y());
        this->addRect(m_pressPoint->x(), m_pressPoint->y(),
                      m_releasePoint->x(), m_pressPoint->y());
    }else{
        cout << "UnknownButtonReleased" << endl;
    }
}

void MouseScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    cout << event->scenePos().x() << ", " << event->scenePos().y() << endl;
}
