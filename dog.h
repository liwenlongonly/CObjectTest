//
// Created by ilong on 2022/3/22.
//

#ifndef CTEST_DOG_H
#define CTEST_DOG_H

#include "animal.h"

// 定义子类结构
typedef struct {
    Animal parent; // 第一个位置放置父类结构
    int legs;      // 添加子类自己的属性
}Dog;

// 子类构造函数声明
void Dog_Ctor(Dog *this, char * name, int age, int weight, int legs);

// 子类属性声明
inline int Dog_GetLegs(Dog *this);

#endif //CTEST_DOG_H
