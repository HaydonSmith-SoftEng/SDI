#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QResizeEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{

    QString imagePath = QFileDialog::getOpenFileName(

                this,

                tr("Open File"),

                "",

                tr("JPEG (.jpg *.jpeg);;PNG (.png)" )
                );

    imageObject = new QImage();
    imageObject->load(imagePath);
    image = QPixmap::fromImage(*imageObject);

    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());

    ui->Disp->setScene(scene);
}
//void MainWindow::on_pushButton_clicked()   //Code for image file selection
//{
//    QString fileName=QFileDialog::getOpenFileName(this,tr("c:"), "", tr("images(*.png *.jpeg *..bmp *.gif)"));

//    imageObject = new QImage();
//    imageObject ->load(fileName);
//    image = QPixmap::fromImage(*imageObject);

//    scene = new QGraphicsScene(this);
//    scene->addPixmap(image);
//    scene->setSceneRect(image.rect());
//    image = image.scaledToWidth(ui->Disp->width(),Qt::SmoothTransformation);      //scales the image to the width and height of the label
//    image = image.scaledToHeight(ui->Disp->height(),Qt::SmoothTransformation);
//     ui->Disp->setScene(scene);

//}


//Select which tool to use.
void MainWindow::on_Rect_clicked() //This is the square tool code
{

    QPen blackpen(Qt::black);
    blackpen.setWidth(6);

    square=scene ->addRect(10,10,100,100,blackpen);
    square->setFlag(QGraphicsItem::ItemIsMovable);
}


void MainWindow::on_Triangle_clicked() //this is the triangle tool code
{
    QPainter painter(this);

    QPolygon Tri;
    Tri << QPoint(300,00);
    Tri << QPoint(100,500);
    Tri << QPoint(500,500);

    painter.drawPolygon(Tri);
    scene->addPolygon(Tri);
}


void MainWindow::on_Pent_clicked() //this is the Pentagon tool code
{
    QPainter painter(this);

    QPolygon pent;
    pent << QPoint(300,00);
    pent << QPoint(100,200);
    pent << QPoint(200,500);
    pent << QPoint(400,500);
    pent << QPoint(500,200);

    painter.drawPolygon(pent);
    scene->addPolygon(pent);
}

void MainWindow::on_oct_clicked() //this is the Octagon tool code
{
    QPainter painter(this);

    QPolygon oct;
    oct << QPoint(300,00);
    oct << QPoint(100,200);
    oct << QPoint(100,400);
    oct << QPoint(300,600);
    oct << QPoint(500,600);
    oct << QPoint(700,400);
    oct << QPoint(700,200);
    oct << QPoint(500,00);

    painter.drawPolygon(oct);
    scene->addPolygon(oct);
}






void MainWindow::on_saveButton_pressed()

{

    QString imagePath = QFileDialog::getSaveFileName(

                this,

                tr("Save File"),

                "",

                tr("JPEG (.jpg *.jpeg);;PNG (.png)" )
               );

    *imageObject = image.toImage();

    imageObject->save(imagePath);

}


//void MainWindow::on_saveButton_clicked() //Code for saving the image when finished
//{
//    QString fileName = QFileDialog::getSaveFileName(this,tr("c:"),tr("AnnotatedImage.png"));
//    *imageObject = image.toImage();
//    imageObject->save(fileName);
//}






