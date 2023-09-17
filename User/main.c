/*
 在 RT-Thread 中，凡是涉及到数据类型的地方，RTThread 都会将标准的 C 数据类型用 typedef 重新取一个类型名，以“rt”前缀开头。
 这些经过重定义的数据类型放在 rtdef.h这个头文件
 */
//================================ 包含的头文件 ================================
#include <stdio.h>
#include "../rtthread/include/rtthread.h"

//================================ 全局变量 ================================
rt_uint8_t flag1;
rt_uint8_t flag2;

extern rt_list_t  rt_thread_priority_table[RT_THREAD_PRIORITY_MAX];
//================================ 线程控制块 & STACK & 线程声明 ================================

struct rt_thread rt_flag1_thread;                   // 定义线程控制块
struct rt_thread rt_flag2_thread;

ALIGN(RT_ALIGN_SIZE)                                // 设置变量需要多少个字节对齐，对在它下面的变量起作用。ALIGN是一个带参宏，在 rtdef.h 中定义
                                                    // RT_ALIGN_SIZE 是一个在rtconfig.h中定义的宏，默认为 4，表示 4 个字节对齐
rt_uint8_t rt_flag1_thread_stack[512];              // 定义线程栈：一个预先定义好的全局数据，数据类型为rt_uint8_t，大小设置为512。
rt_uint8_t rt_flag2_thread_stack[512];
// 线程声明
_Noreturn void flag1_thread_entry(void *p_arg);

_Noreturn void flag2_thread_entry(void *p_arg);



int main() {
    // 硬件初始化
    // 将硬件相关的初始化放在这里，如果是软件仿真则没有相关初始化代码

    // 调度器初始化
    rt_system_scheduler_init();

    // 初始化线程：栈、函数、控制块最终联系起来。
    rt_thread_init(&rt_flag1_thread,                            // 线程控制块
                   flag1_thread_entry,                          // 线程入口地址（无限for循环）
                   RT_NULL,                           // 线程形参
                   &rt_flag1_thread_stack[0],         // 线程栈地址
                   sizeof(rt_flag1_thread_stack));              // 线程栈大小

    // 将线程插入到就绪列表
    rt_list_insert_before(&(rt_thread_priority_table[0]),    //TODO
                          &(rt_flag1_thread.tlist));            //TODO

    // 初始化线程
    rt_thread_init(&rt_flag2_thread,                            // 线程控制块
                   flag2_thread_entry,                          // 线程入口地址（无限for循环）
                   RT_NULL,                           // 线程形参
                   &rt_flag2_thread_stack[0],         // 线程栈地址
                   sizeof(rt_flag2_thread_stack));              // 线程栈大小
    // 将线程插入到就绪列表
    rt_list_insert_before(&(rt_thread_priority_table[0]),     //TODO
                          &(rt_flag1_thread.tlist));            //TODO

    // 启动系统调度器
    rt_system_scheduler_start();
}

//================================ 函数实现 =============================================================================
// 软件延时
void delay(rt_uint32_t count){
    for (; count != 0; count--);
}

_Noreturn void flag1_thread_entry(void *p_arg){
    for(;;){
        flag1 = 1;
        delay(100);
        flag1 = 0;
        delay(100);
        rt_schedule();      // 线程切换：这里是手动切换
    }
}

_Noreturn void flag2_thread_entry(void *p_arg){
    for (;;) {
        flag2 = 1;
        delay(100);
        flag2 = 0;
        delay(100);
        rt_schedule();      // 线程切换：这里是手动切换
    }
}


