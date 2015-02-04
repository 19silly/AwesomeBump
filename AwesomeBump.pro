CONFIG       += c++11 debug release
QT           += opengl gui widgets

VPATH += ../shared
INCLUDEPATH += ../shared

HEADERS       = glwidget.h \
    mainwindow.h \
    CommonObjects.h \
    formimageprop.h \
    glimageeditor.h \
    camera.h \
    dialogheightcalculator.h \
    qopenglerrorcheck.h
SOURCES       = glwidget.cpp \
                main.cpp \
    mainwindow.cpp \
    formimageprop.cpp \
    glimageeditor.cpp \
    CommonObjects.cpp \
    camera.cpp \
    dialogheightcalculator.cpp

# install
INSTALLS += target

RESOURCES += \
    content.qrc

FORMS += \
    mainwindow.ui \
    formimageprop.ui \
    dialogheightcalculator.ui

ICON = content/icon.icns
