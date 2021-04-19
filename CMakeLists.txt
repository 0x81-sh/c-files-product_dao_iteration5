cmake_minimum_required(VERSION 3.17)
project(product_dao_iteration5 C)

set(CMAKE_C_STANDARD 11)

add_executable(product_dao_iteration5 main.c backend.c backend.h product.c product.h product_dao.c product_dao.h product_csv.c product_csv.h)