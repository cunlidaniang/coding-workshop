cmake_minimum_required(VERSION 3.16)

project(Matrix)

aux_source_directory(./src DIR_SRCS)

include_directories(include)
include_directories(/usr/local/OpenBLAS.OpenMP/lib/include)

add_compile_options(-O3 -march=native)

add_executable(main ${DIR_SRCS})

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    message("OpenMP found.")
    target_link_libraries(main PUBLIC OpenMP::OpenMP_C /usr/local/OpenBLAS.OpenMP/lib/libopenblas.a)
endif()