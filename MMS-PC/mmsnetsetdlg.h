#ifndef MMSNETSETDLG_H
#define MMSNETSETDLG_H

#include <QDialog>

namespace Ui {
    class MMSNetSetDlg;
}

class MMSNetSetDlg : public QDialog
{
    Q_OBJECT

public:
    explicit MMSNetSetDlg(QWidget *parent = nullptr);
    ~MMSNetSetDlg();

public:
    void getNetSet(QString &strIP, QString &strPort);

protected:
    void _startListen();
    void _cancel();

private:
    Ui::MMSNetSetDlg *ui;
};

#endif // MMSNETSETDLG_H
