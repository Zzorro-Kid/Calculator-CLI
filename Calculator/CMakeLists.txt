cmake_minimum_required(VERSION 3.10)
project(Calculator C)

set(CMAKE_C_STANDARD 11)

# 1) Указываем, что runtime-файлы (бинарники) должны оказаться в корне проекта
#    PROJECT_SOURCE_DIR — это /home/gleb/ClionProjects/Calculator
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

# 2) Собираем исполняемый калькулятор
add_executable(calculator main.c)

# 3) После сборки копируем calculator -> calculator.exe в тот же каталог (корень проекта)
add_custom_command(TARGET calculator POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "$<TARGET_FILE:calculator>"
        "${PROJECT_SOURCE_DIR}/calculator.exe"
)

# 4) При конфигурации создаём в корне проекта скрипт run_calculator.sh
#    (чтобы сразу после сборки он уже лежал рядом с main.c)
file(WRITE "${PROJECT_SOURCE_DIR}/run_calculator.sh"
        "#!/bin/bash
./calculator
")

# 5) Делаем этот скрипт исполнителем
file(CHMOD "${PROJECT_SOURCE_DIR}/run_calculator.sh"
        PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
        GROUP_READ GROUP_EXECUTE
        WORLD_READ WORLD_EXECUTE
)
