#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;  
}


void Dialog::on_pushButton_released()
{
    /*
     * getOpenFileName(parent, caption, dir)
     */
    QString fileName = QFileDialog::getOpenFileName(this, "open a file", "C://");
    if (fileName == ""){
        return;
    }
    // debug用
    //QMessageBox::information(this, "success", fileName);
    setGraphcsView(fileName);
}


void Dialog::setGraphcsView(QString filePath){
    // イメージファイルを読み込む
    QImage image(filePath);

    // QImageをQPixmapに変更
    QPixmap pixmap = QPixmap::fromImage(image);
    // QPixmapをQGraphicsPixmapItemに変換する
    QGraphicsPixmapItem *imageItem = new QGraphicsPixmapItem(pixmap);
    // QGraphicsPixmapItemをsceneに追加する

    // sceneのインスタンス化, sceneはQGraphicsSceneを継承している
    scene = new MouseScene;
    scene->addItem(imageItem);

    // sceneの背景、QGraphicsViewをgrayにする
    ui->graphicsView->setBackgroundBrush(QBrush(Qt::gray));
     // sceneをQGraphicsViewに設定する。
    ui->graphicsView->setScene(scene);

}



















