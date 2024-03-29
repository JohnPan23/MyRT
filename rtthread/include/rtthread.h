//
// Created by Administrator on 2023/8/21.
//

#ifndef MYRT_RTTHREAD_H
#define MYRT_RTTHREAD_H


/*
*************************************************************************
*                             包含的头文件
*************************************************************************
*/
#include "rtdef.h"
#include "rtservice.h"
#include "../../User/rtconfig.h"

/*
*************************************************************************
*                               函数声明
*************************************************************************
*/
/*
-------------------------------------------------------------------------
*                               线程接口
-------------------------------------------------------------------------
*/



//线程初始化：栈、函数、控制块最终联系起来
rt_err_t rt_thread_init(struct rt_thread                *thread,
                        void              (*entry)(void *parameter),
                        void                            *parameter,
                        void                            *stack_start,
                        rt_uint32_t                      stack_size);

rt_err_t rt_thread_resume(rt_thread_t thread);

rt_err_t rt_thread_startup(rt_thread_t thread);
/*
-------------------------------------------------------------------------
*                             调度器接口
-------------------------------------------------------------------------
*/
void rt_system_scheduler_init(void);
void rt_schedule_insert_thread(struct rt_thread *thread);
void rt_system_scheduler_start(void);
void rt_schedule(void);

#endif //MYRT_RTTHREAD_H