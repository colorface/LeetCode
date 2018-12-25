//
//  __myAtoi.c
//  LeetCode
//
//  Created by AIR on 2018/9/11.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/*
 字符串转整数
 测试用例：
 -5-    =>  -5
 +-2    =>  0
   00223    =>223
 0-4    =>0;
 0  2233    =>0
 
 //说明：c中32位 最大数INT_MAX ,最小数INT_MIN,如果在范围外，需要拓展为long型，
 */

int myAtoi(char *str) {
    
    //字串为空
    if (!str)
        return 0;
    
    char *p = NULL;//保留可用转换子串
    char *q = NULL;//恢复可用转换子串
    int sigin = 0; //标记正负状态
    int flag = 0;  //额外判断字段，出现0，则为1，0后不为数字，用以返回结果
    
    while (*str != '\0') {
        
        //遍历字串
        if (*str == ' ') {
            //用以判断0后' '型字串，eg："00  223"
            if (flag) {
                return 0;
            }
            *str++;
            continue;
        }
        if (*str == 48) {
            *str++;
            flag = 1;
            continue;
        }
        //如果存在0，并且*str当前值不为1~9，则返回0
        if (flag && !(*str > 48 && *str <=57)) {
            return 0;
        }
        
        //当前*str为+，-，1~9时，保留子串指针
        if (*str == '+' || *str == '-' || (*str >48 && *str <= 57)) {
            p = str;
            break;
        }
        
        
        return 0;
    }
    //当无子串时，返回0
    if (!p) {
        return 0;
    }
    //q用于记录指针p
    q = p;
    
    while (*p != '\0') {
        //判断+，-情况 ，标记sigin
        if (*p == '+' || *p == '-') {
            if (*p == '-' && p == q) sigin = 1;
            if(p!=q) {
                break;
            }
            
            //去+，-号
            p++;
            q = p;
        }
        
        //如果后跟+，-号，返回0
        if (*p == '+' || *p == '-') {
            return 0;
        }
        //如果后跟0~9
        if (*p >= 48 && *p <= 57) {
            p++;
        }else {
            *p = '\0';
            break;
        }
    }
    p = q;
    
    if (sigin==1) {
        return -atol(p) < INT_MIN ? INT_MIN : -atol(p);
    }
    return atol(p)>INT_MAX ? INT_MAX : atol(p);
}
