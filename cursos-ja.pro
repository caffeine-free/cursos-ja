QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/classes/course_impl.cpp \
    src/classes/user_impl.cpp \
    src/lib/model_impl.cpp \
    src/main.cpp \
    views/addcourse.cpp

HEADERS += \
    src/classes/course.h \
    src/classes/course_impl.h \
    src/classes/user.h \
    src/classes/user_impl.h \
    src/lib/model.h \
    src/lib/model_impl.h \
    views/addcourse.h

FORMS += \
    views/addcourse.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
