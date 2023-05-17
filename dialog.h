#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QImage>
#include <QPixmap>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>

#include <mousescene.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_released();

private:
    Ui::Dialog *ui;
    //QGraphicsScene scene;
    void setGraphcsView(QString filePath);

    // MouseSceneはQGraphicsSceneを継承している
    MouseScene *scene;

};
#endif // DIALOG_H
