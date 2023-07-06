cmake_minimum_required(VERSION 3.15)
project(example)

set(EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV 4.5.4 REQUIRED)  # OpenCV'yi bulun ve belirli sürümü belirtin

include_directories(${OpenCV_INCLUDE_DIRS})  # OpenCV include dizinlerini ekleyin

add_executable(main main.cpp)
target_link_libraries(main PRIVATE ${OpenCV_LIBS})  # OpenCV kütüphanelerini bağlayın
