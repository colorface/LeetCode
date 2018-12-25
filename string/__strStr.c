//
//  __strStr.c
//  LeetCode
//
//  Created by AIR on 2018/9/10.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>
#include <string.h>

/*
 实现 strStr() 函数。
 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1
 
 测试用例:       "hello", "ll"  =>2
                "aaaaa","bba" =>-1
 
 */
int strStr(char *haystack, char *needle){
    
    int i = 0;          //记录下标
    int count = 0;      //记录相同元素个数
    char *tmp = needle; //指针重置
    while (*needle != '\0' && *haystack != '\0') {
        
        if (*needle == *haystack) {
            
            count++;
            needle++;
        }else {
            //减去已记录元素个数
            if (count) {
                i -= count;
                haystack -= count;
                needle = tmp;   //  指针重置
                count = 0;      //  计数重置
            }
        }
        
        i++;            //  记录下标
        haystack++;     //  指针偏移
    }

    if (count == strlen(tmp)) {
        return i-count;
    }
    
    return -1;
}
