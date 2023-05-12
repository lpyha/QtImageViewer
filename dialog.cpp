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
    scene.addItem(imageItem);

     // sceneをQGraphicsViewに設定する。
    ui->graphicsView->setScene(&scene);
}
