cmake_minimum_required(VERSION 3.5)
project(nixMetaFS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/abstractions/IModel.h src/core/BaseModel.h src/Common.h src/models/Metadata.h src/dal/nixDal.cpp src/dal/nixDal.h src/dal/MySqlRequest.cpp src/dal/MySqlRequest.h)
add_executable(nixMetaFS ${SOURCE_FILES} src/abstractions/IModel.h src/core/BaseModel.h src/Common.h src/models/Metadata.h src/dal/nixDal.cpp src/dal/nixDal.h src/dal/MySqlRequest.cpp src/dal/MySqlRequest.h)