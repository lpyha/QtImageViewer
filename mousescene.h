#ifndef MOUSESCENE_H
#define MOUSESCENE_H

/*
 *QGraphicsSceneでイベントを捕まえるにはそれを継承したクラスを作成する
 */

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneMoveEvent>
#include <iostream>
using namespace std;

class MouseScene : public QGraphicsScene
{
public:
    explicit MouseScene(QObject *parent = nullptr);

private slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // MOUSESCENE_H
