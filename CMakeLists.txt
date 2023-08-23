cmake_minimum_required(VERSION 3.25)
project(MyRT C)

set(CMAKE_C_STANDARD 11)

add_executable(MyRT User/main.c rtthread/include/rtdef.h rtthread/include/rtservice.h rtthread/include/rtthread.h User/rtconfig.h rtthread/include/rthw.h rtthread/src/thread.c rtthread/src/scheduler.c)
