cmake_minimum_required(VERSION 3.25)
project(EjemploTeoriaArboles C)

set(CMAKE_C_STANDARD 11)

add_executable(Arboles_Punteros main.c arboles_punteros.c arboles_punteros.h)
add_executable(Arboles_Binarios_Busqueda main.c abb.c abb.h main2.c)
