// Created by Glin on 2023/5/24.
#include <stdio.h>
#include <ctype.h>

int main(){
    char str[10] = "1hello";
    if(isdigit(str[0]))
        printf("Hello, world!\n");
    printf("%d", isdigit('1'));
    return 0;
}

//struct student{
//    char name[10];
//    char sex[5];
//    int number;
//};
//
//int main(){
//    /* 举个例子 */
//    struct student *stu1;
//    /* 必须为结构体指针分配内存 */
//    stu1 = (struct student *) malloc(sizeof(struct student));
//    stu1->number = 10;
//    char s[10] = "li";
//    /* C语言数组在定义之后，不允许再次进行赋值，仅允许修改和读取操作 */
////    stu1->name = s;
//    strcpy(stu1->name, "li");
//    strcpy(stu1->sex, "男");
//    printf("%s\n", stu1->name);
//    printf("%s\n", stu1->sex);
//    printf("%d\n", stu1->number);
//    /* 释放分配在堆的内存 */
//    free(stu1);
//    return 0;
//}
