#include <stdio.h>

#include "animal.h"
#include "dog.h"
#include "rt_list.h"

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
    Animal_Ctor(&a, "hello",1, 3);
    printf("age = %d, weight = %d \n",
           Animal_GetAge(&a),
           Animal_GetWeight(&a));

    Dog d;
    Dog_Ctor(&d, "dog2",10, 30, 4);
    printf("age = %d, weight = %d, legs = %d \n",
           Animal_GetAge(&d),
           Animal_GetWeight(&d),
           Dog_GetLegs(&d));

    // 把子类对象赋值给父类指针
    Animal *pa = (Animal*)&d;

    // 传递父类指针，将会调用子类中实现的虚函数。
    Animal_Say(pa);

    Dog dog;

    Dog_Ctor(&dog, "dog3",11, 31, 4);

    Animal_Say((Animal *)&dog);

    struct Person p1;
    strcpy(p1.name, "p1");
    rt_list_init(&p1.node);

    struct Person p2;
    strcpy(p2.name, "p2");
    rt_list_insert_before(&p1.node, &p2.node);

    struct Person p3;
    strcpy(p3.name, "p3");
    rt_list_insert_before(&p1.node, &p3.node);

    struct Person p4;
    strcpy(p4.name, "p4");
    rt_list_insert_before(&p1.node, &p4.node);

    struct Person p5;
    strcpy(p5.name, "p5");
    rt_list_insert_before(&p1.node, &p5.node);

    rt_list_t *node = &p1.node;
    for (int i = 0; i < 5; ++i) {
        struct Person *p = rt_list_entry(node, struct Person, node);
        if(p){
            printf(" person name %s \n",p->name);
        }
        node = node->next;
    }

    return 0;
}
