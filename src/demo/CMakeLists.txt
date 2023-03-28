cmake_minimum_required(VERSION 3.16)

set(TARGET_NAME ${PROJECT_NAME}-demo )

add_executable(${TARGET_NAME}
    main.cpp
    )
target_link_libraries(${TARGET_NAME} ${PROJECT_NAME})
target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})