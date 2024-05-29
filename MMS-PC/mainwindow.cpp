#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MMSCustomSeachBox.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 3);

    ui->searchBox->addWidget(new MMSCustomSearchBox(this));

    _initTreeWidget();
    _initTableWidget();

    connect(ui->treeWidget, &QTreeWidget::itemClicked, this, &MainWindow::_treeItemChanged);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::_initTreeWidget()
{
    // All
    QTreeWidgetItem *ptrAllItem = new QTreeWidgetItem();
    ptrAllItem->setText(0, QObject::tr("All"));
    ptrAllItem->setIcon(0, QIcon(":/resource/all.png"));
    ptrAllItem->setData(0, Qt::UserRole, MMSTreeItemCol::ticAll);
    ui->treeWidget->addTopLevelItem(ptrAllItem);

    // Out
    QTreeWidgetItem *ptrOutItem = new QTreeWidgetItem();
    ptrOutItem->setText(0, QObject::tr("Out"));
    ptrOutItem->setIcon(0, QIcon(":/resource/out.png"));
    ptrOutItem->setData(0, Qt::UserRole, MMSTreeItemCol::ticOut);
    ptrAllItem->addChild(ptrOutItem);

    // Into
    QTreeWidgetItem *ptrIntoItem = new QTreeWidgetItem();
    ptrIntoItem->setText(0, QObject::tr("Into"));
    ptrIntoItem->setIcon(0, QIcon(":/resource/into.png"));
    ptrIntoItem->setData(0, Qt::UserRole, MMSTreeItemCol::ticInto);
    ptrAllItem->addChild(ptrIntoItem);

    ui->treeWidget->expandAll();
}

void MainWindow::_initTableWidget()
{
    auto head = ui->tableWidget->horizontalHeader();
    QList<int> lstHeadWidth;
    QList<Qt::Alignment> lsyHeadAlign, lstDataAlign;

    lstHeadWidth << 80 << 120 << 120 << 120;
    std::for_each(lstHeadWidth.begin(), lstHeadWidth.end(),
                  [=](int nWidth) { head->resizeSection(lstHeadWidth.indexOf(nWidth), nWidth); });
    head->setDefaultAlignment(Qt::AlignCenter);
}

void MainWindow::_treeItemChanged()
{
    auto item = ui->treeWidget->currentItem();
    if (item == nullptr)
        return;

    auto traverse = [=](MMSMaterialState eType) -> vecMaters {
        vecMaters vecRet;
        std::for_each(m_vecAll.begin(), m_vecAll.end(), [&](MMSMaterialDataBasePtr ptr) {
            if (ptr == nullptr)
                return;
            if (ptr->getState() == eType)
                vecRet.push_back(ptr);
        });
        return vecRet;
    };

    MMSMaterialState type = MMSMaterialState(item->data(0, Qt::UserRole).toInt());
    _displayData(traverse(type));
}

void MainWindow::_displayData(vecMaters vecData)
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(vecData.size());

    for (int i = 0; i < vecData.size(); ++i) {
        auto ptr = vecData.at(i);
        if (ptr == nullptr)
            continue;

        ui->tableWidget->setItem(i, MMSTableFeilCol::tfcIndex, new QTableWidgetItem(QString::number(i + 1)));
        ui->tableWidget->setItem(i, MMSTableFeilCol::tfcName, new QTableWidgetItem(ptr->getName()));
        ui->tableWidget->setItem(i, MMSTableFeilCol::tfcQuality,
                                 new QTableWidgetItem(QString::number(ptr->getQuality())));
        ui->tableWidget->setItem(i, MMSTableFeilCol::tfcState,
                                 new QTableWidgetItem(ptr->getState() == MMSMaterialState::msOut
                                                          ? QObject::tr("Out")
                                                          : QObject::tr("Into")));
    }
}
