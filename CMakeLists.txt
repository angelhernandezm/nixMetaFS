cmake_minimum_required(VERSION 3.5)
project(nixMetaFS CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
set(GLib_COMPILE_RESOURCES glib-compile-resources)

execute_process(COMMAND glib-compile-resources --generate-source --target "/home/angel/Code/clion/nixMetaFS/src/resources/generated/nix-metafs-properties.cpp" "/home/angel/Code/clion/nixMetaFS/src/resources/nix-MetaFS.gresource.xml")

execute_process(COMMAND cp -rf "/home/angel/Code/clion/nixMetaFS/src/miscellaneous/nixMetaFS.xml" "/home/angel/Code/clion/nixMetaFS/bin/nixMetaFS.xml")

include(FindPkgConfig)

pkg_check_modules(GTK gtk+-3.0 REQUIRED)
pkg_check_modules(libglade-2.0 REQUIRED)
pkg_check_modules(libtinyxml2-2v5 REQUIRED)

include_directories(${GTK_INCLUDE_DIRS})
link_directories(${LIBMYSQLCLIENT_LIBRARY_DIRS})
set(SOURCE_FILES src/main.cpp src/abstractions/IModel.h src/core/BaseModel.h src/Common.h src/models/Metadata.h src/dal/nixDal.cpp src/dal/nixDal.h src/dal/MySqlRequest.cpp src/dal/MySqlRequest.h src/abstractions/IDisposable.h src/core/BaseController.cpp src/core/BaseController.h src/app/MainWindowController.cpp src/app/MainWindowController.h src/core/ConfigReader.cpp src/core/ConfigReader.h src/models/Config.cpp src/models/Config.h src/models/ConnectionString.cpp src/models/ConnectionString.h src/models/Command.cpp src/models/Command.h src/models/AppSetting.cpp src/models/AppSetting.h src/core/LinqCore.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
add_executable(nixMetaFS ${SOURCE_FILES} src/resources/generated/nix-metafs-properties.cpp src/abstractions/IModel.h src/core/BaseModel.h src/Common.h src/models/Metadata.h src/dal/nixDal.cpp src/dal/nixDal.h src/dal/MySqlRequest.cpp src/dal/MySqlRequest.h src/core/BaseController.cpp src/core/BaseController.h src/app/MainWindowController.cpp src/app/MainWindowController.h src/core/ConfigReader.cpp src/core/ConfigReader.h src/models/Config.cpp src/models/Config.h src/models/ConnectionString.cpp src/models/ConnectionString.h src/models/Command.cpp src/models/Command.h src/models/AppSetting.cpp src/models/AppSetting.h src/core/LinqCore.h)
target_link_libraries(${PROJECT_NAME} ${GTK_LIBRARIES} mysqlcppconn stdc++fs tinyxml)
