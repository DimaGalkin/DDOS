
cmake_minimum_required(VERSION 3.1)

project(kernel VERSION 1.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

file(GLOB LIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.c")

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/kernel.c)

set(ASM ${CMAKE_CURRENT_SOURCE_DIR}/boot.s)

set(LINKER_SCRIPT "linker.ld")

add_compile_options("-ffreestanding")
add_link_options("-nostdlib")

set_property(SOURCE ${ASM} APPEND PROPERTY COMPILE_OPTIONS "-x" "assembler-with-cpp")

add_executable(Kernel.bin ${SOURCES} ${LIB_SOURCES} ${ASM})

execute_process(
    COMMAND bash -c "./buildiso.sh"

    #COMMAND bash -c "qemu-system-x86_64 -cdrom Kernel.iso"
)