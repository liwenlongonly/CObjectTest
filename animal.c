//
// Created by ilong on 2022/3/22.
//

#include "animal.h"
#include <assert.h>

__attribute__((constructor)) void init(void)
{
    printf("constructor run...\n");
}

__attribute__((destructor)) void finish(void)
{
    printf("destructor run...\n");
}

// 父类中虚函数的具体实现
static void _Animal_Say(Animal *this)
{
    // 因为父类Animal是一个抽象的东西，不应该被实例化。
    // 父类中的这个虚函数不应该被调用，也就是说子类必须实现这个虚函数。
    // 类似于C++中的纯虚函数。
    assert(0);
}

// 父类构造函数实现
void Animal_Ctor(Animal *this, int age, int weight)
{
    // 首先定义一个虚表
    static struct AnimalVTable animal_vtbl = {&_Animal_Say};
    // 让虚表指针指向上面这个虚表
    this->vptr = &animal_vtbl;
    this->age = age;
    this->weight = weight;
}

int Animal_GetAge(Animal *this)
{
    return this->age;
}

int Animal_GetWeight(Animal *this)
{
    return this->weight;
}

// 测试多态：传入的参数类型是父类指针
void Animal_Say(Animal *this)
{
    // 如果this实际指向一个子类Dog对象，那么this->vptr这个虚表指针指向子类自己的虚表，
    // 因此，this->vptr->say将会调用子类虚表中的函数。
    this->vptr->say(this);
}