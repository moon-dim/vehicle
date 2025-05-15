cmake_minimum_required(VERSION 3.10)
project(vehicle)

# 设置C标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 定义关键路径变量
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/c/src)   # 源文件目录
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/c/include)      # 头文件目录
set(LIB_DIR ${CMAKE_SOURCE_DIR}/libs)               # 库文件目录

# 查找Python3开发环境
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

# 添加头文件搜索路径
include_directories(
  ${INCLUDE_DIR}
  ${Python3_INCLUDE_DIRS}
  /usr/include/cjson
  /usr/include/iniparser
)

# 自动收集所有源文件
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/*.c")

#排除C扩展
list(REMOVE_ITEM SOURCES "${PROJECT_SOURCE_DIR}/py_c_utils/c_utilsmoudle.c")

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接所有需要的库
target_link_libraries(${PROJECT_NAME} PRIVATE
  iniparser    # libiniparser.so
  cjson        # libcjson.so
  mosquitto    # libmosquitto.so
  pthread
  wiringPi
  mosquittopp  # libmosquittopp.so
  zlog         # libzlog.so
  sqlite3      # libsqlite3.so
  c_utils
  ${Python3_LIBRARIES}
  ${Python3_LINK_OPTIONS}
)

add_subdirectory(${PROJECT_SOURCE_DIR}/py_c_utils)

# 设置可执行文件输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)