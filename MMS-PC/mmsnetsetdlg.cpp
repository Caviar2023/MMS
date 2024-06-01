#include "mmsnetsetdlg.h"
#include "ui_mmsnetsetdlg.h"
#include <QNetworkInterface>

MMSNetSetDlg::MMSNetSetDlg(QWidget *parent) : QDialog(parent), ui(new Ui::MMSNetSetDlg)
{
    ui->setupUi(this);

    // 获取本地IP地址
    auto lstIP = QNetworkInterface::allInterfaces();
    for (auto &ip : lstIP) {
        auto lstAddr = ip.addressEntries();
        for (auto &addr : lstAddr) {
            if (addr.ip().protocol() == QAbstractSocket::IPv4Protocol)
                ui->listIP->addItem(addr.ip().toString());
        }
    }

    connect(ui->btnListen, &QPushButton::clicked, this, &MMSNetSetDlg::_startListen);
    connect(ui->btnCancel, &QPushButton::clicked, this, &MMSNetSetDlg::_cancel);
}

MMSNetSetDlg::~MMSNetSetDlg() { delete ui; }

void MMSNetSetDlg::getNetSet(QString &strIP, QString &strPort)
{
    strIP = ui->listIP->currentText();
    strPort = ui->portLine->text();
}

void MMSNetSetDlg::_startListen()
{
    ui->btnListen->setEnabled(false);
    accept();
}

void MMSNetSetDlg::_cancel() { close(); }
