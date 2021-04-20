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
    src/lib/register_impl.cpp \
    src/main.cpp \
    tests/functional/functional_tests.cpp \
    tests/unit/unit_course.cpp \
    tests/unit/unit_user.cpp \
    views/clientcontrol.cpp \
    views/clientpage.cpp \
    views/editclient.cpp \
    views/editcourse.cpp \
    views/login.cpp \
    views/login_admpage.cpp \
    views/registerview.cpp

HEADERS += \
    src/classes/course.h \
    src/classes/course_impl.h \
    src/classes/user.h \
    src/classes/user_impl.h \
    src/lib/model.h \
    src/lib/model_impl.h \
    src/lib/register.h \
    src/lib/register_impl.h \
    tests/functional/functional_tests.h \
    tests/unit/unit_course.h \
    tests/unit/unit_user.h \
    views/clientcontrol.h \
    views/clientpage.h \
    views/editclient.h \
    views/editcourse.h \
    views/login.h \
    views/login_admpage.h \
    views/registerview.h

FORMS += \
    views/clientcontrol.ui \
    views/clientpage.ui \
    views/editclient.ui \
    views/editcourse.ui \
    views/login.ui \
    views/login_admpage.ui \
    views/registerview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
