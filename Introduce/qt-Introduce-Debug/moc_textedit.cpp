/****************************************************************************
** Meta object code from reading C++ file 'textedit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../textedit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TextEdit_t {
    QByteArrayData data[25];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TextEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TextEdit_t qt_meta_stringdata_TextEdit = {
    {
QT_MOC_LITERAL(0, 0, 8), // "TextEdit"
QT_MOC_LITERAL(1, 9, 6), // "closed"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 7), // "fileNew"
QT_MOC_LITERAL(4, 25, 8), // "fileOpen"
QT_MOC_LITERAL(5, 34, 8), // "fileSave"
QT_MOC_LITERAL(6, 43, 10), // "fileSaveAs"
QT_MOC_LITERAL(7, 54, 8), // "textBold"
QT_MOC_LITERAL(8, 63, 13), // "textUnderline"
QT_MOC_LITERAL(9, 77, 10), // "textItalic"
QT_MOC_LITERAL(10, 88, 10), // "textFamily"
QT_MOC_LITERAL(11, 99, 1), // "f"
QT_MOC_LITERAL(12, 101, 8), // "textSize"
QT_MOC_LITERAL(13, 110, 1), // "p"
QT_MOC_LITERAL(14, 112, 9), // "textStyle"
QT_MOC_LITERAL(15, 122, 10), // "styleIndex"
QT_MOC_LITERAL(16, 133, 9), // "textColor"
QT_MOC_LITERAL(17, 143, 9), // "textAlign"
QT_MOC_LITERAL(18, 153, 8), // "QAction*"
QT_MOC_LITERAL(19, 162, 1), // "a"
QT_MOC_LITERAL(20, 164, 24), // "currentCharFormatChanged"
QT_MOC_LITERAL(21, 189, 15), // "QTextCharFormat"
QT_MOC_LITERAL(22, 205, 6), // "format"
QT_MOC_LITERAL(23, 212, 21), // "cursorPositionChanged"
QT_MOC_LITERAL(24, 234, 20) // "clipboardDataChanged"

    },
    "TextEdit\0closed\0\0fileNew\0fileOpen\0"
    "fileSave\0fileSaveAs\0textBold\0textUnderline\0"
    "textItalic\0textFamily\0f\0textSize\0p\0"
    "textStyle\0styleIndex\0textColor\0textAlign\0"
    "QAction*\0a\0currentCharFormatChanged\0"
    "QTextCharFormat\0format\0cursorPositionChanged\0"
    "clipboardDataChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   95,    2, 0x0a /* Public */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    1,  102,    2, 0x08 /* Private */,
      12,    1,  105,    2, 0x08 /* Private */,
      14,    1,  108,    2, 0x08 /* Private */,
      16,    0,  111,    2, 0x08 /* Private */,
      17,    1,  112,    2, 0x08 /* Private */,
      20,    1,  115,    2, 0x08 /* Private */,
      23,    0,  118,    2, 0x08 /* Private */,
      24,    0,  119,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TextEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TextEdit *_t = static_cast<TextEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->fileNew(); break;
        case 2: _t->fileOpen(); break;
        case 3: { bool _r = _t->fileSave();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->fileSaveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->textBold(); break;
        case 6: _t->textUnderline(); break;
        case 7: _t->textItalic(); break;
        case 8: _t->textFamily((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->textSize((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->textStyle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->textColor(); break;
        case 12: _t->textAlign((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 13: _t->currentCharFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 14: _t->cursorPositionChanged(); break;
        case 15: _t->clipboardDataChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TextEdit::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TextEdit::closed)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TextEdit::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TextEdit.data,
      qt_meta_data_TextEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TextEdit.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void TextEdit::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
