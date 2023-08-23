//
// Created by Administrator on 2023/8/21.
//
#include "../include/rtthread.h"
#include "../include/rthw.h"

rt_err_t rt_thread_init(struct rt_thread               *thread,
                        void             (*entry)(void *parameter),
                        void                           *parameter,
                        void                           *stack_start,
                        rt_uint32_t                     stack_size){
    //初始化线程链表节点
    rt_list_init(&(thread->tlist));
    //线程入口地址
    thread->entry      = (void *)entry;
    //线程形参
    thread->parameter  =         parameter;
    //线程起始地址
    thread->stack_addr =         stack_start;
    //线程栈大小
    thread->stack_size =         stack_size;

    //初始化线程栈，并返回线程栈指针
    thread->sp         = (void *)rt_hw_stack_init(thread->entry,
                                                  thread->parameter,
                                                  (void *)((char *)thread->stack_addr + thread->stack_size - 4));
}