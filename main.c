#include <stdio.h>

#include "animal.h"
#include "dog.h"

// c语言面向对象开发，封装、继承、多态

__attribute__((constructor)) void init(void){
    printf("constructor run...\n");
}

__attribute__((destructor)) void finish(void){
    printf("destructor run...\n");
}

int main() {
    printf("c语言面向对象开发，封装、继承、多态!\n");

    // 在栈上创建一个对象
    Animal a;
    // 构造对象
    Animal_Ctor(&a, 1, 3);
    printf("age = %d, weight = %d \n",
           Animal_GetAge(&a),
           Animal_GetWeight(&a));

    Dog d;
    Dog_Ctor(&d, 10, 30, 4);
    printf("age = %d, weight = %d, legs = %d \n",
           Animal_GetAge(&d),
           Animal_GetWeight(&d),
           Dog_GetLegs(&d));

    // 把子类对象赋值给父类指针
    Animal *pa = (Animal*)&d;

    // 传递父类指针，将会调用子类中实现的虚函数。
    Animal_Say(pa);

    return 0;
}
