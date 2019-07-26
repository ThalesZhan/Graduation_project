#ifndef PRO_REC_H
#define PRO_REC_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>
#include "shape_pro.h"
#include "chalky_pro.h"
#include "rec.h"
using namespace std;

namespace Ui {
class Pro_Rec;
}

class Pro_Rec : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pro_Rec(QWidget *parent = 0);
    ~Pro_Rec();

    string filename;
    string pro_type;
    vector<int> para;

    shape_pro shape;
    chalky_pro chalky;
    rec check;

public slots:
    void get_Filename();
    void initialize();

private slots:
    void on_radioButton_shape_clicked(bool checked);

    void on_radioButton_chalky_clicked(bool checked);

    void on_convert_clicked();

    void on_denoising_clicked();

    void on_splitback_clicked();

    void on_pushButton_clicked();

    void on_histogram_clicked();

    void on_gparameters_clicked();

    void on_recgonization_clicked();

private:
    Ui::Pro_Rec *ui;
};

#endif // PRO_REC_H
