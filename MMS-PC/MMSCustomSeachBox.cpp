#include "MMSCustomSeachBox.h"

MMSCustomSearchBox::MMSCustomSearchBox(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(300,28);
    m_strSeachText = "";
    QLineEdit *pLineEdit = new QLineEdit(this);
    pLineEdit->setPlaceholderText("Search");
    QAction *pAction = new QAction(this);
    pAction->setIcon(QIcon(":/resource/search.png"));
    pLineEdit->addAction(pAction, QLineEdit::LeadingPosition);

    connect(pAction, &QAction::triggered, [=]() {
        m_strSeachText = pLineEdit->text();
        if (m_strSeachText.isEmpty())
            return;
        emit sigSeach(m_strSeachText);
    });
}

MMSCustomSearchBox::~MMSCustomSearchBox() {}
