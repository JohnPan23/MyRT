//
// Created by Administrator on 2023/8/21.
//

#ifndef MYRT_RTSERVICE_H
#define MYRT_RTSERVICE_H

#include "rtdef.h"

/* 已知一个结构体里面的成员的地址，反推出该结构体的首地址 */
#define         rt_container_of(ptr, type, member)      ((type *)((char *)(ptr) - (unsigned long)(&((type *)0)->member)))
#define         rt_list_entry(node, type, member)       rt_container_of(node, type, member)

/*
*************************************************************************
*                           双向链表操作相关函数
*************************************************************************
*/

/* 初始化链表节点 */
rt_inline void rt_list_init(rt_list_t *l){
    l->next=l;
    l->prev=l;
}

/* 在双向链表头部插入一个节点 */
rt_inline void rt_list_insert_after(rt_list_t *l,
                                    rt_list_t *n){
    //三步
    // 1、解决l下家
    l->next->prev = n;
    // 2、解决n
    n->next=l->next;
    // 3、解决l
    l->next=n;
    n->prev=l;
}

/* 在双向链表尾部插入一个节点 */
rt_inline void rt_list_insert_before(rt_list_t *l,
                                     rt_list_t *n){
    //三步
    // 1、解决l上家
    l->prev->next=n;
    // 2、解决n
    n->prev=l->prev;
    // 3、解决l
    l->prev=n;
    n->next=l;
}
/* 从双向链表删除一个节点 */
rt_inline void rt_list_remove(rt_list_t *n){
    n->next->prev=n->prev;
    n->prev->next=n->next;
    //记得清空n
    n->next=n->prev=n;
}














































#endif //MYRT_RTSERVICE_H
