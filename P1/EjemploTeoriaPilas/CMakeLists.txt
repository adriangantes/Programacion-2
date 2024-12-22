cmake_minimum_required(VERSION 3.25)
project(EjemploTeoriaPilas C)

set(CMAKE_C_STANDARD 11)

add_executable(Pilas_arrays main.c pilas_array.c pilas_array.h)
add_executable(Pilas_punteros main.c pilas_punteros.c pilas_punteros.h)