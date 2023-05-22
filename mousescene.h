#ifndef MOUSESCENE_H
#define MOUSESCENE_H

/*
 *QGraphicsSceneでイベントを捕まえるにはそれを継承したクラスを作成する
 */

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneMoveEvent>
#include <QPoint>
#include <QRect>
#include <iostream>
using namespace std;

class MouseScene : public QGraphicsScene
{
public:
    explicit MouseScene(QObject *parent = nullptr);

private slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    Qt::MouseButton m_button;
    QPoint *m_pressPoint;
    QPoint *m_releasePoint;
};

#endif // MOUSESCENE_H
