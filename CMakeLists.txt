cmake_minimum_required(VERSION 3.10)
project(vehicle)

# 设置C标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 定义关键路径变量
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src/source)   # 源文件目录
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src/include)         # 头文件目录
set(LIB_DIR ${CMAKE_SOURCE_DIR}/src/lib)                 # 库文件目录
set(ETC_DIR ${CMAKE_SOURCE_DIR}/etc)                     # 配置文件目录

# 添加头文件搜索路径
include_directories(
  ${INCLUDE_DIR}
  /usr/include/cjson
  /usr/include/iniparser
) 
# 自动收集所有源文件
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/*.c")

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接所有需要的库（按实际依赖顺序排列）
target_link_libraries(${PROJECT_NAME} PRIVATE
  iniparser    # libiniparser.so
  cjson        # libcjson.so
  mosquitto    # libmosquitto.so
  pthread
  wiringPi
  mosquittopp  # libmosquittopp.so
  zlog         # libzlog.so
  sqlite3      # libsqlite3.so
)

# 设置可执行文件输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)