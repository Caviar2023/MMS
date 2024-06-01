#include "MMSCustomSeachBox.h"
#include "MMSTypeDef.h"

MMSCustomSearchBox::MMSCustomSearchBox(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(300, 23);
    m_strSeachText = "";
    QLineEdit *pLineEdit = new QLineEdit(this);
    pLineEdit->setPlaceholderText("Search");
    QAction *pAction = new QAction(this);
    pAction->setIcon(QIcon(":/icon/resource/search.png"));
    pLineEdit->addAction(pAction, QLineEdit::TrailingPosition);

    connect(pAction, &QAction::triggered, [=]() {
        m_strSeachText = pLineEdit->text();
        if (m_strSeachText.isEmpty())
        {
            QMessageBox::information(this, tr("Search"), tr("Please input search text!"));
            return;
        }
        emit sigSeach(m_strSeachText);
    });
}

MMSCustomSearchBox::~MMSCustomSearchBox() {}
