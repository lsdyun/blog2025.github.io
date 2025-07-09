cmake_minimum_required(VERSION 3.16)

project(QStyle VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加 QuickControls2 模块
find_package(Qt6 REQUIRED COMPONENTS Quick QuickControls2)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appQStyle
    main.cpp
)

# 修复 QML 模块声明：添加 OUTPUT_DIRECTORY 和 明确指定 QML 类型
qt_add_qml_module(appQStyle
    URI QStyle
    VERSION 1.0
    OUTPUT_DIRECTORY qml
    QML_FILES
        Main.qml
        RESOURCES qtquickcontrols2.conf
        RESOURCES file.qrc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appQStyle PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appQStyle
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# 链接 QuickControls2 模块
target_link_libraries(appQStyle
    PRIVATE
        Qt6::Quick
        Qt6::QuickControls2  # 添加这个关键模块
)

include(GNUInstallDirs)
install(TARGETS appQStyle
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
