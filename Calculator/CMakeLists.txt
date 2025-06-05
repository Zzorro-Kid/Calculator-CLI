cmake_minimum_required(VERSION 3.10)
project(Calculator C)

set(CMAKE_C_STANDARD 11)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(calculator main.c)


add_custom_command(TARGET calculator POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "$<TARGET_FILE:calculator>"
        "${PROJECT_SOURCE_DIR}/calculator.exe"
)


file(WRITE "${PROJECT_SOURCE_DIR}/run_calculator.sh"
        "#!/bin/bash
./calculator
")

file(CHMOD "${PROJECT_SOURCE_DIR}/run_calculator.sh"
        PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
        GROUP_READ GROUP_EXECUTE
        WORLD_READ WORLD_EXECUTE
)
