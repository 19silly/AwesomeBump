TEMPLATE      = app
CONFIG       += c++11
QT           += opengl gui widgets

# QtnProperty project source files
# open the QtnProperty project and
# compile it. Then compile AB
TOP_BUILD_DIR=utils/QtnProperty
BIN_DIR = $$TOP_BUILD_DIR/bin
LIBS += -L$$BIN_DIR -lQtnPropertyCore -lQtnPropertyWidget

include($$TOP_BUILD_DIR/Common.pri)
PEG_TOOL = $$BIN_DIR/QtnPEG
include($$TOP_BUILD_DIR/PEG.pri)

INCLUDEPATH += utils/QtnProperty/Core
INCLUDEPATH += utils/QtnProperty/PropertyWidget


PEG_SOURCES += properties/Filter3DDOF.pef \
               properties/Filter3DBloom.pef \
               properties/Filter3DLensFlares.pef \
               properties/Filter3DToneMapping.pef \
               properties/GLSLParsedFragShader.pef \
               properties/ImageProperties.pef \
               properties/Filters3D.pef


DESTDIR = Build/Bin
OBJECTS_DIR = Build/Obj
MOC_DIR = Build/Ui
UI_DIR = Build/Ui
RCC_DIR = Build/Obj


CONFIG(release_gl330) {
    #This is a release build
    DEFINES += USE_OPENGL_330
    TARGET = AwesomeBumpGL330
} else {
    TARGET = AwesomeBump
    #This is a debug build
}

# It's now required to define the path for resource files
# at compile time
# To keep compatibility with older releases, the application
# continues to look for these resource files in its current
# directory's subfolders (Config/* and Core/*) when using
# qmake to compile
DEFINES += RESOURCE_BASE=\\\"./\\\"

VPATH += ../shared
INCLUDEPATH += ../shared include \
               utils/

HEADERS = glwidget.h \
    mainwindow.h \
    CommonObjects.h \
    formimageprop.h \
    glimageeditor.h \
    camera.h \
    dialogheightcalculator.h \
    qopenglerrorcheck.h \
    utils/Mesh.hpp \
    utils/tinyobj/tiny_obj_loader.h \
    formsettingsfield.h \
    formsettingscontainer.h \
    utils/qglbuffers.h \
    dialoglogger.h \
    glwidgetbase.h \
    formbasemapconversionlevels.h \
    formmaterialindicesmanager.h \
    dialogshortcuts.h \
    allaboutdialog.h \    
    formimagebase.h \
    dockwidget3dsettings.h \
    gpuinfo.h \
    properties/Dialog3DGeneralSettings.h \
    utils/glslshaderparser.h \
    utils/glslparsedshadercontainer.h

SOURCES = glwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    formimageprop.cpp \
    glimageeditor.cpp \
    CommonObjects.cpp \
    camera.cpp \
    dialogheightcalculator.cpp \
    utils/Mesh.cpp \
    utils/tinyobj/tiny_obj_loader.cc \
    formsettingsfield.cpp \
    formsettingscontainer.cpp \
    utils/qglbuffers.cpp \
    dialoglogger.cpp \
    glwidgetbase.cpp \
    formbasemapconversionlevels.cpp \
    formmaterialindicesmanager.cpp \
    dialogshortcuts.cpp \
    allaboutdialog.cpp \
    formimagebase.cpp \
    dockwidget3dsettings.cpp \
    gpuinfo.cpp \
    properties/Dialog3DGeneralSettings.cpp \
    utils/glslshaderparser.cpp \
    utils/glslparsedshadercontainer.cpp


RESOURCES += content.qrc

RC_FILE = icon.rc

FORMS += \
    mainwindow.ui \
    formimageprop.ui \
    dialogheightcalculator.ui \
    formsettingsfield.ui \
    formsettingscontainer.ui \
    dialoglogger.ui \
    formbasemapconversionlevels.ui \
    formmaterialindicesmanager.ui \
    allaboutdialog.ui \
    dialogshortcuts.ui \
    dockwidget3dsettings.ui \
    properties/Dialog3DGeneralSettings.ui

ICON = resources/icon.icns

DISTFILES += \
    resources/quad.obj \
    properties/Filter3DDOF.pef \
    properties/Filter3DBloom.pef \
    properties/Filter3DLensFlares.pef \
    properties/Filter3DToneMapping.pef \
    properties/Filters3D.pef \
    properties/GLSLParsedFragShader.pef \
    properties/ImageProperties.pef


# install additional files into target destination
# (require "make install")
config.path = $$OUT_PWD/$$DESTDIR
config.files += ../Bin/Configs ../Bin/Core
INSTALLS += config

exists("../Third/QtnProperty/QtnProperty.pri") {
  DEFINES += HAVE_QTNPROP
  include("../Third/QtnProperty/QtnProperty.pri")
}
