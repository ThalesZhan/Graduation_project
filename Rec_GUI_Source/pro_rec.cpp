#include "pro_rec.h"
#include "ui_pro_rec.h"
#include <iostream>
using namespace std;

Pro_Rec::Pro_Rec(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pro_Rec)
{
    ui->setupUi(this);
    connect(ui->actionReadFile_2, SIGNAL(triggered()), this, SLOT(get_Filename()));
    connect(ui->actionInitialize, SIGNAL(triggered()), this, SLOT(initialize()));
}

Pro_Rec::~Pro_Rec()
{
    delete ui;
}

void Pro_Rec::get_Filename()
{
    QFileDialog dia;
    dia.resize(400,300);
    QString tem_str = dia.getOpenFileName(this);

    QPixmap *pixmap = new QPixmap(tem_str);
    pixmap->scaled(ui->show_img->size(), Qt::KeepAspectRatio);
    ui->show_img->setScaledContents(true);
    ui->show_img->setPixmap(*pixmap);

    filename = tem_str.toStdString();
}

void Pro_Rec::on_radioButton_shape_clicked(bool checked)
{
    if(checked)
        pro_type = "Shape";
}

void Pro_Rec::on_radioButton_chalky_clicked(bool checked)
{
    if(checked)
        pro_type = "Chalky";
}

void Pro_Rec::initialize()
{
    if(pro_type == "Shape")
        shape.shape_read(filename);
    else if(pro_type == "Chalky")
        chalky.chalky_read(filename);
}

void Pro_Rec::on_convert_clicked()
{
    cv::Mat mat_img;
    if(pro_type == "Shape")
        mat_img = shape.cvImg();
    else if(pro_type == "Chalky")
        mat_img = chalky.cvImg();

    QImage q_img((unsigned char*)mat_img.data, mat_img.cols,
                 mat_img.rows, mat_img.step, QImage::Format_Grayscale8);

    QPixmap *pixmap = new QPixmap(QPixmap::fromImage(q_img));
    pixmap->scaled(ui->show_img->size(), Qt::KeepAspectRatio);
    ui->show_img->setScaledContents(true);
    ui->show_img->setPixmap(*pixmap);
}

void Pro_Rec::on_denoising_clicked()
{
    cv::Mat mat_img;
    if(pro_type == "Shape")
        mat_img = shape.Denoising();
    else if(pro_type == "Chalky")
        mat_img = chalky.Denoising();

    QImage q_img((unsigned char*)mat_img.data, mat_img.cols,
                 mat_img.rows, mat_img.step, QImage::Format_Grayscale8);

    QPixmap *pixmap = new QPixmap(QPixmap::fromImage(q_img));
    pixmap->scaled(ui->show_img->size(), Qt::KeepAspectRatio);
    ui->show_img->setScaledContents(true);
    ui->show_img->setPixmap(*pixmap);
}

void Pro_Rec::on_splitback_clicked()
{
    cv::Mat mat_img;
    if(pro_type == "Shape")
        mat_img = shape.splitBack();
    else if(pro_type == "Chalky")
        mat_img = chalky.splitBack();

    QImage q_img((unsigned char*)mat_img.data, mat_img.cols,
                 mat_img.rows, mat_img.step, QImage::Format_Grayscale8);

    QPixmap *pixmap = new QPixmap(QPixmap::fromImage(q_img));
    pixmap->scaled(ui->show_img->size(), Qt::KeepAspectRatio);
    ui->show_img->setScaledContents(true);
    ui->show_img->setPixmap(*pixmap);
}

void Pro_Rec::on_pushButton_clicked()
{
    if(pro_type == "Shape")
    {
        cv::Mat img = shape.splitBack();
        cv::Mat mat_img;
        cv::Canny(img, mat_img, 0, 255);

        QImage q_img((unsigned char*)mat_img.data, mat_img.cols,
                     mat_img.rows, mat_img.step, QImage::Format_Grayscale8);

        QPixmap *pixmap = new QPixmap(QPixmap::fromImage(q_img));
        pixmap->scaled(ui->show_img->size(), Qt::KeepAspectRatio);
        ui->show_img->setScaledContents(true);
        ui->show_img->setPixmap(*pixmap);
    }
}

void Pro_Rec::on_histogram_clicked()
{
    if(pro_type == "Chalky")
    {
        chalky.getHistogram();
        cv::Mat mat_img;
        mat_img = chalky.drawHistogram();

        QImage q_img((unsigned char*)mat_img.data, mat_img.cols,
                     mat_img.rows, mat_img.step, QImage::Format_Grayscale8);

        QPixmap *pixmap = new QPixmap(QPixmap::fromImage(q_img));
        pixmap->scaled(ui->show_img->size(), Qt::KeepAspectRatio);
        ui->show_img->setScaledContents(true);
        ui->show_img->setPixmap(*pixmap);
    }
}


void Pro_Rec::on_gparameters_clicked()
{
    if(pro_type == "Shape")
        para = shape.calParameters();
    else if (pro_type == "Chalky")
        para = chalky.calParameters();
}

void Pro_Rec::on_recgonization_clicked()
{
    check.rec_read(para, pro_type);
    string result = check.recg_img();
    QString q_result = QString::fromStdString(result);

    shape.shape_clean();
    chalky.chalky_clean();

    ui->show_result->setText(q_result);
}
