//
// Created by ilong on 2022/3/22.
//

#ifndef CTEST_ANIMAL_H
#define CTEST_ANIMAL_H

#include <stdio.h>
#include <string.h>
#include "log.h"

struct AnimalVTable;  // 父类虚表的前置声明

// 定义父类结构
typedef struct {
    struct AnimalVTable *vptr; // 虚表指针
    int age;
    int weight;
    char name[10];
} Animal;

// 父类中的虚表
struct AnimalVTable{
    void (*say)(Animal *this); // 虚函数指针
};

// 父类中实现的虚函数
void Animal_Say(Animal *this);

// 构造函数声明
void Animal_Ctor(Animal *this, char * name, int age, int weight);

// 获取父类属性声明
inline int Animal_GetAge(Animal *this);
inline int Animal_GetWeight(Animal *this);

#endif //CTEST_ANIMAL_H
