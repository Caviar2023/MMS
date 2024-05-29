#ifndef MMS_CUSTOM_SEARCH_BOX_H
#define MMS_CUSTOM_SEARCH_BOX_H

#include <QLineEdit>
#include <QAction>

class MMSCustomSearchBox : public QWidget
{
    Q_OBJECT

public:
    MMSCustomSearchBox(QWidget *parent = nullptr);
    ~MMSCustomSearchBox();
    
public:
signals:
    void sigSeach(const QString &strText);

private:
    QString m_strSeachText;
};

#endif // MMS_CUSTOM_SEARCH_BOX_H