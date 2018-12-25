//
//  __countAndSay.c
//  LeetCode
//
//  Created by AIR on 2018/9/12.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 报数
 报数序列是指一个整照其中的整数的顺序进数序列，按行报数，得到下一个数。其前五项如下：
 
 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221
 1 被读作  "one 1"  ("一个一") , 即 11。
 11 被读作 "two 1s" ("两个一"）, 即 21。
 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 
 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
 
 注意：整数顺序将表示为一个字符串
 */

char *sayCount(char *s,int n) {
    
    //申请堆内存，用于存储字串，25时已超过1000，故预设10000
    char *p = (char *)malloc(sizeof(char) * 10000);
    //设置内存初值
    memset(p, 0, sizeof(char)*10000);
    
    char i = *s;    //保存当前数字,预设为首字母
    int j=0;        //保存当前数字出现次数
    int k=0;        //p的索引
    
    while (*s != '\0') {
        
        if (i == *s) {
            j++;
            s++;
            
            //
            if (*s != '\0') {
                continue;
            }
            
        }else {
            //回退一位，中和s++操作
            s--;
        }
        //当前i值报数完成，因为每次报数均需要两位，第一位为出现数字的次数，第二位为出现的数字
        p[k] = j + '0';
        p[k+1] = i;
        k+=2;
        
        //移到下一位进行，进行报数
        i = *(s+1);
        //还原初始值
        j = 0;
        
        //报数完成，则退出循环
        if (*s == '\0') {
            break;
        }
        s++;
    }
    //
//    if (k == 0) {
//        p[k] = j + '0';
//        p[k+1] = i;
//    }
    s = p;
    
    if ((n-1) == 0) {
        return p;
    }
    return sayCount(s,--n);
}

char *countAndSay(int n) {
    
    if (n == 1)  return "1";
    if (n == 2)  return "11";
    if (n == 3)  return "21";
    
    n -= 3;
    return sayCount("21",n);
}
