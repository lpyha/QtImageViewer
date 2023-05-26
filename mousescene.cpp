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
        QPen pen(Qt::red);
        pen.setWidth(5);

        QPen penRect(Qt::blue);
        penRect.setWidth(5);

        /*
         *　(始点x, 始点y, 終点x, 終点y)であることに注意しろ
         */
        this->addLine(m_pressPoint->x(), m_pressPoint->y(),
                      m_releasePoint->x(), m_releasePoint->y(), pen);

        this->addRect(m_pressPoint->x(), m_pressPoint->y(),
                      abs(m_pressPoint->x() - m_releasePoint->x()),
                      abs(m_pressPoint->y() - m_releasePoint->y()),
                      penRect);

    }else{
        cout << "UnknownButtonReleased" << endl;
    }

    cout << m_pressPoint->x() << ", " << m_pressPoint->y() << endl;
    cout << m_releasePoint->x() << ", " << m_releasePoint->y() << endl;

}

void MouseScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    cout << event->scenePos().x() << ", " << event->scenePos().y() << endl;
}
