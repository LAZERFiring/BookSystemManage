cmake_minimum_required(VERSION 3.14)

project(QtBookSystemManage LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(QtBookSystemManage
  main.cpp Login.cpp Login.h Login.ui
  User.h User.cpp
  SystemUi.cpp SystemUi.h SystemUi.ui
  UserManage.h UserManage.cpp
  UserManageWidget.h UserManageWidget.cpp
  ReaderManage.h ReaderManage.cpp
  Reader.h Reader.cpp
  ReaderManageWidget.h ReaderManageWidget.cpp
)
target_link_libraries(QtBookSystemManage Qt${QT_VERSION_MAJOR}::Widgets)

install(TARGETS QtBookSystemManage
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
