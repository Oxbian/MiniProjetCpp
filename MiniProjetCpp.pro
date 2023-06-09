######################################################################
# Automatically generated by qmake (3.1) Tue Apr 18 16:54:58 2023
######################################################################

TEMPLATE = app
TARGET = MiniProjetCpp
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += include/interface/FenetrePrincipale.hpp \
           include/interface/GrandeVue.hpp \
           include/interface/MiniVue.hpp \
           include/interface/SceneCarte.hpp \
           include/interface/LoginDialog.hpp

SOURCES += src/interface/FenetrePrincipale.cpp \
           src/interface/GrandeVue.cpp \
           src/interface/main.cpp \
           src/interface/MiniVue.cpp \
           src/interface/SceneCarte.cpp \
           src/interface/LoginDialog.cpp
           
QT += widgets
QMAKE_CXXFLAGS += -std=c++14 -g
INCLUDEPATH += "include" \
               "include/interface" \
               "lib/libBDD/include"
LIBS += lib/libBDD/libBDD.a
LIBS += -lmysqlcppconn