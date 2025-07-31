cmake_minimum_required(VERSION 3.31)
project(questao1 C)

set(CMAKE_C_STANDARD 11)

# Configurações comuns para todos os executáveis
#set(COMMON_SOURCES main.c)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads REQUIRED)

# principal, tudo junto
add_executable(questao1_principal ${COMMON_SOURCES} principal.c)
target_compile_definitions(questao1_principal PRIVATE SEQUENTIAL_VERSION=1)

# a
add_executable(questao1_item_a ${COMMON_SOURCES} item_a.c)
target_compile_definitions(questao1_item_a PRIVATE ${CMAKE_THREAD_LIBS_INIT})

## a
#add_executable(questao1_itemA ${COMMON_SOURCES} itemA.c)
#target_compile_definitions(questao1_itemA PRIVATE ${CMAKE_THREAD_LIBS_INIT})
#
## g
#add_executable(questao1_itemG ${COMMON_SOURCES} itemG.c)
#target_link_libraries(questao1_itemG PRIVATE ${CMAKE_THREAD_LIBS_INIT})