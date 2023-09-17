//
// Created by Administrator on 2023/8/21.
//

#ifndef MYRT_RTDEF_H
#define MYRT_RTDEF_H

/*
*************************************************************************
*                               数据类型
*************************************************************************
*/
typedef                             int rt_bool_t;

typedef                     signed char rt_int8_t;
typedef                   unsigned char rt_uint8_t;

typedef                    signed short rt_int16_t;
typedef                  unsigned short rt_uint16_t;

typedef                     signed long rt_int32_t;
typedef                   unsigned long rt_uint32_t;
typedef                                 rt_uint32_t rt_time_t;
typedef                                 rt_uint32_t rt_tick_t;

typedef                            long rt_base_t;
typedef                                 rt_base_t rt_err_t;
typedef                                 rt_base_t rt_flag_t;
typedef                                 rt_base_t rt_off_t;

typedef                   unsigned long rt_ubase_t;
typedef                                 rt_ubase_t rt_size_t;
typedef                                 rt_ubase_t rt_dev_t;






#ifdef __CC_ARM
    #define rt_inline                   static __inline
		#define ALIGN(n)                    __attribute__((aligned(n)))
#elif defined (__IAR_SYSTEMS_ICC__)
    #define rt_inline                   static inline
		#define ALIGN(n)                    PRAGMA(data_alignment=n)
#elif defined (__GNUC__)
    #define rt_inline                   static __inline
        #define ALIGN(n)                    __attribute__((aligned(n)))
#else
    #error not supported tool chain


#endif
#define                                 RT_NULL   (0)
#define                                 RT_TRUE    1
#define                                 RT_FALSE   0

#define                                 RT_ALIGN     (size, align)      (((size) + (align) - 1) & ~((align) - 1))
#define                                 RT_ALIGN_DOWN(size, align)      (( size               ) & ~((align) - 1))

/*
*************************************************************************
*                               错误码定义
*************************************************************************
*/
/* RT-Thread 错误码重定义 */
#define                                 RT_EOK      0               /**< There is no error */
#define                                 RT_ERROR    1               /**< A generic error happens */
#define                                 RT_ETIMEOUT 2               /**< Timed out */
#define                                 RT_EFULL    3               /**< The resource is full */
#define                                 RT_EEMPTY   4               /**< The resource is empty */
#define                                 RT_ENOMEM   5               /**< No memory */
#define                                 RT_ENOSYS   6               /**< No system */
#define                                 RT_EBUSY    7               /**< Busy */
#define                                 RT_EIO      8               /**< IO error */
#define                                 RT_EINTR    9               /**< Interrupted system call */
#define                                 RT_EINVAL   10              /**< Invalid argument */

//======================================= 双向链表结构体 ==================================================================
struct rt_list_node {
    struct rt_list_node *next;              /* 指向后一个节点 */
    struct rt_list_node *prev;              /* 指向前一个节点 */
};
typedef struct rt_list_node rt_list_t;


//======================================== 线程结构体 ====================================================================

struct rt_thread {                      // 定义线程控制块变量，就使用形式：struct rt_thread 变量名
    void        *stack_addr;            // 线程起始地址
    void        *entry;	                // 线程入口地址：无限for循序函数
    void        *parameter;	            // 形参
    void        *sp;	                // 栈地址
    rt_uint32_t stack_size;             // 栈大小，单位为字节

    rt_list_t   tlist;                  // 线程链表节点
};


typedef struct rt_thread *rt_thread_t;  // 定义线程控制块指针就使用形式：rt_thread_t 变量名







#endif //MYRT_RTDEF_H
