//
// Created by ilong on 2022/3/22.
//

#include "dog.h"

// 子类中虚函数的具体实现
static void _Dog_Say(Dog *this){
    printf("dag say \n");
}

// 子类构造函数实现
void Dog_Ctor(Dog *this, int age, int weight, int legs){
    // 首先调用父类构造函数。
    Animal_Ctor(&this->parent, age, weight);
    // 定义子类自己的虚函数表
    static struct AnimalVTable dog_vtbl = {_Dog_Say};
    // 把从父类中继承得到的虚表指针指向子类自己的虚表
    this->parent.vptr = &dog_vtbl;
    // 初始化子类自己的属性
    this->legs = legs;
}

int Dog_GetLegs(Dog *this){
    // 子类自己的属性，直接返回
    return this->legs;
}