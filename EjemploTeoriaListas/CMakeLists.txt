cmake_minimum_required(VERSION 3.23)
project(EjemploTeoria C)

set(CMAKE_C_STANDARD 99)

add_executable(Listas_punteros main.c listas_punteros.c listas_punteros.h)
add_executable(Listas_array main.c listas_array.c listas_array.h)
add_executable(Listas_dobles main.c listas_dobles.c listas_dobles.h)
add_executable(Listas_o_arrays main.c listas_o_arrays.c listas_o_arrays.h)
add_executable(Listas_o_punteros main.c listas_o_punteros.c listas_o_punteros.h)
