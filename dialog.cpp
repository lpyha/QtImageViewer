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
    QString file_name = QFileDialog::getOpenFileName(this, "open a file", "C://");
    if (file_name == ""){
        return;
    }
    //QMessageBox::information(this, "success", file_name);
    QPixmap img(file_name);
    ui->label->setPixmap(img);
}

