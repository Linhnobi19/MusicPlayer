/****************************************************************************
** Meta object code from reading C++ file 'MusicController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MusicController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MusicController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MusicController_t {
    QByteArrayData data[28];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MusicController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MusicController_t qt_meta_stringdata_MusicController = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MusicController"
QT_MOC_LITERAL(1, 16, 12), // "modelChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 19), // "currentIndexChanged"
QT_MOC_LITERAL(4, 50, 10), // "changeSong"
QT_MOC_LITERAL(5, 61, 8), // "findSong"
QT_MOC_LITERAL(6, 70, 5), // "value"
QT_MOC_LITERAL(7, 76, 7), // "getTime"
QT_MOC_LITERAL(8, 84, 4), // "next"
QT_MOC_LITERAL(9, 89, 4), // "prev"
QT_MOC_LITERAL(10, 94, 10), // "playRandom"
QT_MOC_LITERAL(11, 105, 5), // "index"
QT_MOC_LITERAL(12, 111, 6), // "source"
QT_MOC_LITERAL(13, 118, 11), // "setPlaylist"
QT_MOC_LITERAL(14, 130, 4), // "path"
QT_MOC_LITERAL(15, 135, 9), // "setRandom"
QT_MOC_LITERAL(16, 145, 7), // "setLoop"
QT_MOC_LITERAL(17, 153, 15), // "saveCurrentSong"
QT_MOC_LITERAL(18, 169, 11), // "currentTime"
QT_MOC_LITERAL(19, 181, 15), // "loadCurrentSong"
QT_MOC_LITERAL(20, 197, 8), // "savePath"
QT_MOC_LITERAL(21, 206, 8), // "loadPath"
QT_MOC_LITERAL(22, 215, 10), // "searchSong"
QT_MOC_LITERAL(23, 226, 12), // "QList<Song*>"
QT_MOC_LITERAL(24, 239, 4), // "name"
QT_MOC_LITERAL(25, 244, 5), // "model"
QT_MOC_LITERAL(26, 250, 10), // "SongModel*"
QT_MOC_LITERAL(27, 261, 12) // "currentIndex"

    },
    "MusicController\0modelChanged\0\0"
    "currentIndexChanged\0changeSong\0findSong\0"
    "value\0getTime\0next\0prev\0playRandom\0"
    "index\0source\0setPlaylist\0path\0setRandom\0"
    "setLoop\0saveCurrentSong\0currentTime\0"
    "loadCurrentSong\0savePath\0loadPath\0"
    "searchSong\0QList<Song*>\0name\0model\0"
    "SongModel*\0currentIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusicController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       2,  136, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,
       4,    0,  101,    2, 0x06 /* Public */,
       5,    1,  102,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    1,  105,    2, 0x02 /* Public */,
       8,    0,  108,    2, 0x02 /* Public */,
       9,    0,  109,    2, 0x02 /* Public */,
      10,    2,  110,    2, 0x02 /* Public */,
      10,    1,  115,    2, 0x22 /* Public | MethodCloned */,
      13,    1,  118,    2, 0x02 /* Public */,
      15,    0,  121,    2, 0x02 /* Public */,
      16,    0,  122,    2, 0x02 /* Public */,
      17,    2,  123,    2, 0x02 /* Public */,
      19,    0,  128,    2, 0x02 /* Public */,
      20,    1,  129,    2, 0x02 /* Public */,
      21,    0,  132,    2, 0x02 /* Public */,
      22,    1,  133,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

 // methods: parameters
    QMetaType::QString, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   12,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    0x80000000 | 23, QMetaType::QString,   24,

 // properties: name, type, flags
      25, 0x80000000 | 26, 0x0049590b,
      27, QMetaType::Int, 0x00495903,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void MusicController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MusicController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->modelChanged(); break;
        case 1: _t->currentIndexChanged(); break;
        case 2: _t->changeSong(); break;
        case 3: _t->findSong((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: { QString _r = _t->getTime((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->next(); break;
        case 6: _t->prev(); break;
        case 7: _t->playRandom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->playRandom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setPlaylist((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->setRandom(); break;
        case 11: _t->setLoop(); break;
        case 12: _t->saveCurrentSong((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->loadCurrentSong(); break;
        case 14: _t->savePath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->loadPath(); break;
        case 16: { QList<Song*> _r = _t->searchSong((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<Song*>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MusicController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicController::modelChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MusicController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicController::currentIndexChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MusicController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicController::changeSong)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MusicController::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicController::findSong)) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SongModel* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MusicController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< SongModel**>(_v) = _t->model(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->currentIndex(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MusicController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setModel(*reinterpret_cast< SongModel**>(_v)); break;
        case 1: _t->setCurrentIndex(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject MusicController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MusicController.data,
    qt_meta_data_MusicController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MusicController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MusicController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MusicController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MusicController::modelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MusicController::currentIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MusicController::changeSong()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MusicController::findSong(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
