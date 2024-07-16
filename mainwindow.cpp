#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDrag>
#include <QMimeData>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create DraggableLabel and add to central widget's layout
    draggableLabel = new DraggableLabel(ui->centralwidget);
    ui->centralwidget->layout()->addWidget(draggableLabel);

    // Connect button click signals to slots
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Trigger drag action when pushButton is clicked
    QDrag *drag = new QDrag(ui->pushButton);
    QMimeData *mimeData = new QMimeData;
    mimeData->setText("rectangle");
    drag->setMimeData(mimeData);

    // Start the drag operation
    Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
}

