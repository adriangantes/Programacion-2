cmake_minimum_required(VERSION 3.24)
project(EjemploTeoriaColas C)

set(CMAKE_C_STANDARD 11)

add_executable(Colas_punteros main.c colas_punteros.c colas_punteros.h)
add_executable(Colas_arrays main.c colas_arrays.c colas_arrays.h)
add_executable(Colas_prioridad main.c colas_prioridad.c colas_prioridad.h)
