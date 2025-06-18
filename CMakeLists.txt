cmake_minimum_required(VERSION 3.10)
project(CppEmployeeSystem)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 开启编译警告和调试信息
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")

# AddressSanitizer 启用（仅GCC/Clang支持）
set(SANITIZER_FLAGS "-fsanitize=address -fno-omit-frame-pointer -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SANITIZER_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SANITIZER_FLAGS}")

# 查找libpqxx
find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

if(NOT PQXX_FOUND)
    message(FATAL_ERROR "libpqxx not found!")
endif()

# 查找nlohmann_json
find_package(nlohmann_json REQUIRED)

# 源文件
set(SOURCES
    main.cxx
    model/Employee.cxx
    service/EmployeeService.cxx
    db/database.cxx
    utils/DbConfig.cxx
)

# 添加可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 包含目录
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PQXX_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/model
    ${CMAKE_CURRENT_SOURCE_DIR}/service
    ${CMAKE_CURRENT_SOURCE_DIR}/db
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

# 链接库
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    ${PQXX_LIBRARIES}
    nlohmann_json::nlohmann_json
)

 