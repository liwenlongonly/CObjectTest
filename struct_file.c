//
// Created by ilong on 2022/3/21.
//

#include "struct_file.h"
#include <stdio.h>

int open(const char *file, int type){
    printf("open(%s, %d) \n",file, type);
}

int read(char *buffer){
    printf("read() \n");
}

int write(char *buffer){
    printf("write() \n");
}

int close(){
    printf("open() \n");
}

static struct file_operations file = {
        &open,
        &read,
        &write,
        &close
};

struct file_operations * get_file_operations(){
    return &file;
}