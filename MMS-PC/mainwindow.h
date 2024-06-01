#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MMSMaterialDataBase.h"

typedef QVector<MMSMaterialDataBasePtr> vecMaters;

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void _initTreeWidget();
    void _initTableWidget();
    void _treeItemChanged();
    void _displayData(vecMaters vecData);
private:
    Ui::MainWindow *ui;
    vecMaters m_vecAll;
};
#endif // MAINWINDOW_H
