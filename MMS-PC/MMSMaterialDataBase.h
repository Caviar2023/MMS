#ifndef MMSMATERIALDATABASE_H
#define MMSMATERIALDATABASE_H

#include "MMSTypeDef.h"

Q_CLASS_DEFINE(MMSMaterialDataBase)
class MMSMaterialDataBase
{
public:
    MMSMaterialDataBase();
    ~MMSMaterialDataBase();

public:
    // name
    QString getName();
    void setName(const QString &strName);

    // Quality
    int getQuality();
    void setQuality(int nQuality);

    // state
    MMSMaterialState getState();
    void setState(MMSMaterialState eState);

private:
    QString m_strName;
    int m_nQuality;
    MMSMaterialState m_eState;
};

#endif // MMSMATERIALDATABASE_H