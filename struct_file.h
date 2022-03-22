//
// Created by ilong on 2022/3/21.
//

#ifndef CTEST_STRUCT_FILE_H
#define CTEST_STRUCT_FILE_H

extern struct file_operations * get_file_operations();

struct file_operations{
    int (*open)(const char *file, int type);
    int (*read)(char *buffer);
    int (*write)(char *buffer);
    int (*close)();
};

#endif //CTEST_STRUCT_FILE_H
