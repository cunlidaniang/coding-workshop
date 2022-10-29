project(Matrix)

aux_source_directory(./src DIR_SRCS)

include_directories(include)

add_executable(main ${DIR_SRCS})