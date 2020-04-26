#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>
#include <QFileDialog>
#include <QString>
#include <QGraphicsRectItem>
#include <QPolygon>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_saveButton_clicked();

    void on_Rect_clicked();

    void on_Pent_clicked();





    void on_Triangle_clicked();

    void on_oct_clicked();

    void on_saveButton_pressed();

    void on_pushButton_pressed();

private:
    Ui::MainWindow *ui;
    QPixmap image;
    QImage *imageObject;
    QGraphicsScene *scene;
    QGraphicsRectItem *square;
    QGraphicsPolygonItem *pentagon;
    //QPaintEvent *e;
};
#endif // MAINWINDOW_H
