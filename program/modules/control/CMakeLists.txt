# ライブラリ追加
file(GLOB STRUCTURE_SOURCES src/*.cpp include/control/*.h include/control/*.hpp)
add_library(control ${CONTROL_SOURCES})

# インクルードディレクトリ追加
target_include_directories(control PUBLIC include)
target_include_directories(control PRIVATE include/control)

# ライブラリをリンク
target_link_libraries(control util)
target_link_libraries(control structure)
target_link_libraries(control BlackLib)
