cmake_minimum_required(VERSION 3.5)
project(nixMetaFS CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include(FindPkgConfig)

pkg_check_modules(GTK gtk+-3.0 REQUIRED)
pkg_check_modules(libglade-2.0 REQUIRED)

include_directories(${GTK_INCLUDE_DIRS})
link_directories(${LIBMYSQLCLIENT_LIBRARY_DIRS})
set(SOURCE_FILES src/main.cpp src/abstractions/IModel.h src/core/BaseModel.h src/Common.h src/models/Metadata.h src/dal/nixDal.cpp src/dal/nixDal.h src/dal/MySqlRequest.cpp src/dal/MySqlRequest.h src/abstractions/IDisposable.h)
add_executable(nixMetaFS ${SOURCE_FILES} src/abstractions/IModel.h src/core/BaseModel.h src/Common.h src/models/Metadata.h src/dal/nixDal.cpp src/dal/nixDal.h src/dal/MySqlRequest.cpp src/dal/MySqlRequest.h)

target_link_libraries(${PROJECT_NAME} ${GTK_LIBRARIES} mysqlcppconn)