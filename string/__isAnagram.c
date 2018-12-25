//
//  __isAnagram.c
//  LeetCode
//
//  Created by AIR on 2018/9/7.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isAnagram(char *s, char *t) {
    
    if (strlen(s) != strlen(t)) {
        return false;
    }
    //堆内新生成一份copy, p代替t进行操作，也可以用栈复制一份
    char *p = (char *)malloc(sizeof(char)*strlen(t));
//    char p[strlen(t)] = (char *)malloc(sizeof(char)*strlen(t));
    
    strcpy(p, t);
    
    bool sameChar;
    
    char *m = p;
    while (*s != '\0') {
        sameChar = false;
        while (*p != '\0') {
            if (*s == *p) {
                sameChar = true;
                while (*(p+1) != '\0') {
                    *p = *(p+1);
                    p++;
                }
                *p = '\0';
            }
            p++;
        }
        if (!sameChar) {
            free(p);
            return false;
        }
        p = m;
        s++;
    }
    free(p);
    
    return true;
}


