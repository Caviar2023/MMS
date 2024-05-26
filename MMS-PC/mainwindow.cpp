#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 3);

    _initTreeWidget();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::_initTreeWidget()
{
    // All
    QTreeWidgetItem *ptrAllItem = new QTreeWidgetItem();
    ptrAllItem->setText(0, QObject::tr("All"));
    ui->treeWidget->addTopLevelItem(ptrAllItem);

    // Out
    QTreeWidgetItem *ptrOutItem = new QTreeWidgetItem();
    ptrOutItem->setText(0, QObject::tr("Out"));
    ptrAllItem->addChild(ptrOutItem);

    // Into
    QTreeWidgetItem *ptrIntoItem = new QTreeWidgetItem();
    ptrIntoItem->setText(0, QObject::tr("Into"));
    ptrAllItem->addChild(ptrIntoItem);

    ui->treeWidget->expandAll();
}

void MainWindow::_initTableWidget()
{
    auto head = ui->tableWidget->horizontalHeader();
    QList<int> lstHeadWidth;
    QList<Qt::Alignment> lsyHeadAlign, lstDataAlign;

    lstHeadWidth << 80 << 120 << 120 << 120;
    lsyHeadAlign << Qt::AlignCenter << Qt::AlignCenter << Qt::AlignCenter << Qt::AlignCenter;
    lstDataAlign << Qt::AlignCenter << Qt::AlignCenter << Qt::AlignCenter << Qt::AlignCenter;
}
