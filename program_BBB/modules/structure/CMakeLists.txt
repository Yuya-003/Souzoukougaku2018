#BlackLibライブラリ追加
file(GLOB BLACKLIB_SOURCES ../../BlackLib/BlackCore.cpp ../../BlackLib/*.h ../../BlackLib/Black*/*.cpp ../../BlackLib/Black*/*.h)
add_library(BlackLib ${BLACKLIB_SOURCES})

#BlackLibインクルードディレクトリ追加
target_include_directories(BlackLib PUBLIC ../../BlackLib)
target_include_directories(BlackLib PRIVATE ../../BlackLib)

# ライブラリ追加
file(GLOB STRUCTURE_SOURCES src/*.cpp include/structure/*.h include/structure/*.hpp)
add_library(structure ${STRUCTURE_SOURCES})

# インクルードディレクトリ追加
target_include_directories(structure PUBLIC include)
target_include_directories(structure PRIVATE include/structure)

# ライブラリをリンク
target_link_libraries(structure util)
target_link_libraries(structure BlackLib)
if(THREADS_HAVE_PTHREAD_ARG)
  target_compile_options(structure PUBLIC "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(structure "${CMAKE_THREAD_LIBS_INIT}")
endif()
