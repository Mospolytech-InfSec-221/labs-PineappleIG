/****************************************************************************
** Meta object code from reading C++ file 'mytcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mytcpserver.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MyTcpServer_t {
    uint offsetsAndSizes[14];
    char stringdata0[12];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[17];
    char stringdata5[19];
    char stringdata6[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MyTcpServer_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MyTcpServer_t qt_meta_stringdata_MyTcpServer = {
    {
        QT_MOC_LITERAL(0, 11),  // "MyTcpServer"
        QT_MOC_LITERAL(12, 18),  // "incomingConnection"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 7),  // "qintptr"
        QT_MOC_LITERAL(40, 16),  // "socketDescriptor"
        QT_MOC_LITERAL(57, 18),  // "clientDisconnected"
        QT_MOC_LITERAL(76, 14)   // "slotServerRead"
    },
    "MyTcpServer",
    "incomingConnection",
    "",
    "qintptr",
    "socketDescriptor",
    "clientDisconnected",
    "slotServerRead"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MyTcpServer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x0a,    1 /* Public */,
       5,    0,   35,    2, 0x0a,    3 /* Public */,
       6,    0,   36,    2, 0x0a,    4 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MyTcpServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpServer::staticMetaObject>(),
    qt_meta_stringdata_MyTcpServer.offsetsAndSizes,
    qt_meta_data_MyTcpServer,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MyTcpServer_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MyTcpServer, std::true_type>,
        // method 'incomingConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qintptr, std::false_type>,
        // method 'clientDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotServerRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MyTcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyTcpServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->incomingConnection((*reinterpret_cast< std::add_pointer_t<qintptr>>(_a[1]))); break;
        case 1: _t->clientDisconnected(); break;
        case 2: _t->slotServerRead(); break;
        default: ;
        }
    }
}

const QMetaObject *MyTcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyTcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyTcpServer.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int MyTcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
