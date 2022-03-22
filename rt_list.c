//
// Created by ilong on 2022/3/22.
//

#include "rt_list.h"

void rt_list_init(rt_list_t *l) {
    l->next = l->prev = l;
}

void rt_list_insert_after(rt_list_t *l, rt_list_t *n) {
    l->next->prev = n; /* 第 1 步 */
    n->next = l->next; /* 第 2 步 */
    l->next = n; /* 第 3 步 */
    n->prev = l; /* 第 4 步 */
}

void rt_list_insert_before(rt_list_t *l, rt_list_t *n) {
    l->prev->next = n; /* 第 1 步 */
    n->prev = l->prev; /* 第 2 步 */
    l->prev = n; /* 第 3 步 */
    n->next = l; /* 第 4 步 */
}

void rt_list_remove(rt_list_t *n) {
    n->next->prev = n->prev; /* 第 1 步 */
    n->prev->next = n->next; /* 第 2 步 */
    n->next = n->prev = n; /* 第 3 步 */
}