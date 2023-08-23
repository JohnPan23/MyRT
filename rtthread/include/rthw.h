//
// Created by Administrator on 2023/8/21.
//

#ifndef MYRT_RTHW_H
#define MYRT_RTHW_H


#include "rtthread.h"

rt_uint8_t *rt_hw_stack_init(void       *tentry,
                             void       *parameter,
                             rt_uint8_t *stack_addr);

void rt_hw_context_switch(rt_uint32_t from,
                          rt_uint32_t to);

void rt_hw_context_switch_to(rt_uint32_t to);

void rt_hw_context_switch_interrupt(rt_uint32_t from,
                                    rt_uint32_t to);










#endif //MYRT_RTHW_H
