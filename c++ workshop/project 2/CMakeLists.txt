project(calculator)

aux_source_directory(./src DIR_SRCS)

include_directories(include)

add_executable(calculator ${DIR_SRCS})