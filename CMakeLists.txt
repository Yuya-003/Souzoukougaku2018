cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

project(procon27 CXX)


# in-sourceビルドの禁止
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-sourceビルドは許可されていません.")
endif()

# コンパイラ表示
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER}")

# モジュール追加
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

# C++コンパイル設定
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")        # C++14を有効化
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast")        # コンパイル時最適化を有効(O0:なし O1:ちょっと O2:結構 O3:すごい Ofast:ワーオ!)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")     # enable all warnings
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-sign-compare") # disable some warnings
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-type-limits")  # disable some warnings
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")     # enable all SSE and AVX

# 出力先を設定
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin CACHE PATH "Output directory for executables")
set(LIBRARY_OUTPUT_PATH    ${CMAKE_BINARY_DIR}/lib CACHE PATH "Output directory for libraries")

# サブディレクトリ追加
add_subdirectory(modules)
add_subdirectory(exe)
