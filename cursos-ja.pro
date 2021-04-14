QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/lib/course_impl.cpp \
    views/add_course.cpp \
    views/delete_course.cpp \
    views/edit_course.cpp \
    views/main.cpp \
    views/read_course.cpp

HEADERS += \
    src/lib/course.h \
    src/lib/course_impl.h \
    views/add_course.h \
    views/delete_course.h \
    views/edit_course.h \
    views/read_course.h

FORMS += \
    views/add_course.ui \
    views/delete_course.ui \
    views/edit_course.ui \
    views/read_course.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
