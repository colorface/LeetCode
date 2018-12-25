//
//  __reverseString.c
//  LeetCode
//
//  Created by AIR on 2018/9/6.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char *reverseString(char *s) {
    
    
    size_t len = strlen(s);
    char *p = s + len - 1;
    char c;
    for (; s < p; s++, p--) {
        c = *s;
        *s = *p;
        *p = c;
    }
    return s;
}


