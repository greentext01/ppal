cmake_minimum_required(VERSION 3.13)
project(ppal)

set(CMAKE_CXX_STANDARD 14)

add_executable(
    ppal
    
    main.cpp
    src/install/shmake.cpp
    src/error/error.cpp
    src/network/downloader.cpp
)

add_compile_options(-Wall -Wextra -Werror)

target_include_directories(ppal PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ppal /usr/lib/libcurl.so)
target_link_libraries(ppal /usr/lib/libarchive.so)