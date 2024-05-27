#ifndef MMSTypeDef_H
#define MMSTypeDef_H

#include <QString>
#include <QSharedPointer>

enum MMSTreeItemCol
{
    ticAll = 0,
    ticOut,
    ticInto,
};

enum MMSTableFeilCol
{
    tfcIndex = 0,
    tfcName,
    tfcQuality,
    tfcState,
};

enum MMSMaterialState
{
    msOut,
    msInto,
};

#endif // MMSTypeDef_H