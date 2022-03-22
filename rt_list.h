//
// Created by ilong on 2022/3/22.
//

#ifndef COBJECTTEST_RT_LIST_H
#define COBJECTTEST_RT_LIST_H

/* 已知一个结构体里面的成员的地址，反推出该结构体的首地址 */
#define rt_container_of(ptr, type, member) \
((type *)((char *)(ptr) - (unsigned long)(&((type *)0)->member)))

#define rt_list_entry(node, type, member) \
rt_container_of(node, type, member)

struct rt_list_node {
    struct rt_list_node *next;
    struct rt_list_node *prev;
};

typedef struct rt_list_node rt_list_t;

inline void rt_list_init(rt_list_t *l);

/* 在双向链表头部插入一个节点 */
inline void rt_list_insert_after(rt_list_t *l, rt_list_t *n);

inline void rt_list_insert_before(rt_list_t *l, rt_list_t *n);

inline void rt_list_remove(rt_list_t *n);

//list test
struct Person{
    int age;
    char name[20];
    rt_list_t node;
};

#endif //COBJECTTEST_RT_LIST_H
