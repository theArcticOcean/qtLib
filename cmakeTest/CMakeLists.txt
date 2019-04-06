cmake_minimum_required(VERSION 2.8)

project(CMakeTest)

set( CMAKE_INSTALL_PREFIX "/usr/local" )
set( QT_QMAKE_EXECUTABLE "/Users/weiyang/Downloads/Qt5.11.2/5.11.2/clang_64/bin/qmake" )
set( Qt5_DIR "/Users/weiyang/Downloads/Qt5.11.2/5.11.2/clang_64/lib/cmake/Qt5" )
set( Qt5Core_DIR "/Users/weiyang/Downloads/Qt5.11.2/5.11.2/clang_64/lib/cmake/Qt5Core" )
set( SOURCES main.cpp mainwindow.cpp )
set( HEADERS mainwindow.h )
set( UIS mainwindow.ui )
set( QRCs mainwindow.qrc )

find_package( Qt5 COMPONENTS widgets REQUIRED )
set( CMAKE_AUTOMOC ON )
qt5_wrap_ui( UI_HEADERS ${UIS} )
qt5_add_resources( QRC_Srcs ${QRCs} )

include_directories( ${CMAKE_CURRENT_BINARY_DIR} )

add_definitions( ${QT_DEFINITIONS} )

add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${HEADERS} ${SOURCES} ${UI_HEADERS} ${QRC_Srcs} )
qt5_use_modules( ${PROJECT_NAME} Core Gui Widgets )

target_link_libraries( ${PROJECT_NAME} ${QT_LIBRARIES} )

#install( TARGETS CMakeTest BUNDLE DESTINATION . ) # /usr/local/bin

set( importFiles Untitled.png mainwindow.ui )
install( FILES ${importFiles} DESTINATION share )
