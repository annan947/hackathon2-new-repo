cmake_minimum_required(VERSION 3.20)
project(hackathon C CXX)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_Declare(raylib
  URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz)
FetchContent_MakeAvailable(raylib)

# ==========================================================
#  class demo: example.cpp
# ==========================================================
add_executable(example example.cpp)
target_link_libraries(example PRIVATE raylib)

# ==========================================================
#  HACKATHON: your program. List every .cpp file here.
#  Made a new class? Add its .cpp file to this list.
#  (Don't list .h files, only .cpp files.)
# ==========================================================
add_executable(main
    main.cpp
    MainHelperList.cpp
    Topics.cpp
    GameDrawing.cpp
)
target_link_libraries(main PRIVATE raylib)
# Make image paths work when launching from build/ as well as from project root.
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/setting.png" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/cats-img.jpg" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/images" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
