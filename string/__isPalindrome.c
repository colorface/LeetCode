//
//  __isPalindrome.c
//  LeetCode
//
//  Created by AIR on 2018/9/7.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


bool avildPalindromeChar(char c) {
    if ((c >=48 && c <= 57) || (c>=97 && c<=122)) {
        return true;
    }
    return false;
}

bool isPalindrome(char *s) {
    
    char *tmp = s;
    while (*s != '\0') {
        if (*s >= 65 && *s <= 90) {
            *s=tolower(*s);
        }
        s++;
    }
    
    s = tmp;
    
    char *p = s + strlen(s) - 1;
    
    
    while (s < p) {
        
        if (!avildPalindromeChar(*s)){
            s++;
            continue;
        }
        if (!avildPalindromeChar(*p)){
            p--;
            continue;
        }
        if ((*s - *p) != 0) {
            return false;
        }
        s++;
        p--;
    }
    
    
    return true;
}

