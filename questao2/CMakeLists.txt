cmake_minimum_required(VERSION 3.31)
project(questao2 C)

set(CMAKE_C_STANDARD 11)

# Configurações comuns para todos os executáveis
#set(COMMON_SOURCES main.c)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads REQUIRED)

# Executável para a parte sequencial (item A)
add_executable(questao2_itemA ${COMMON_SOURCES} itemA.c)
target_compile_definitions(questao2_itemA PRIVATE SEQUENTIAL_VERSION=1)

# Executável para a parte paralela (itens B e C)
add_executable(questao2_itemBC ${COMMON_SOURCES} itemBC.c)
target_link_libraries(questao2_itemBC PRIVATE ${CMAKE_THREAD_LIBS_INIT})