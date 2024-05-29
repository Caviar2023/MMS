#ifndef MMSTypeDef_H
#define MMSTypeDef_H

#include <QString>
#include <QSharedPointer>
#include <QMessageBox>

enum MMSTreeItemCol {
    ticAll = 0,
    ticOut,
    ticInto,
};

enum MMSTableFeilCol {
    tfcIndex = 0,
    tfcName,
    tfcQuality,
    tfcState,
};

enum MMSMaterialState {
    msOut,
    msInto,
};

#define Q_TYPE_DEFINE(_name_)                   \
    class _name_;                               \
    typedef QSharedPointer<_name_> _name_##Ptr; \
    typedef QWeakPointer<_name_> _name_##WPtr;

#define Q_MAKE_SHARED(_name_, ...) QSharedPointer<_name_>::create(__VA_ARGS__);

#define Q_STATIC_CAST(_type_, _ptr_) qSharedPointerCast<_type_>(_ptr_);

#define Q_DYNAMIC_CAST(_type_, _ptr_) qSharedPointerDynamicCast<_type_>(_ptr_);

#endif // MMSTypeDef_H