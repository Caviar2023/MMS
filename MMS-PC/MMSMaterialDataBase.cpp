#include "MMSMaterialDataBase.h"

MMSMaterialDataBase::MMSMaterialDataBase() {}

MMSMaterialDataBase::~MMSMaterialDataBase() {}

QString MMSMaterialDataBase::getName() { return m_strName; }

void MMSMaterialDataBase::setName(const QString &strName) { m_strName = strName; }

int MMSMaterialDataBase::getQuality() { return m_nQuality; }

void MMSMaterialDataBase::setQuality(int nQuality) { m_nQuality = nQuality; }

MMSMaterialState MMSMaterialDataBase::getState() { return m_eState; }

void MMSMaterialDataBase::setState(MMSMaterialState eState) { m_eState = eState; }
