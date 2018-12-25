//
//  __firstUniqChar.c
//  LeetCode
//
//  Created by AIR on 2018/9/7.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

//测试用例:leetcode ==> 0
//cc ==> -1;
//aadadaad => -1;
//a ==> 0;
//空 ==> -1;

int firstUniqChar(char *s) {
    
    //取字串长度-1 最大不超过此值
    int len = (int)strlen(s)-1;
    //
    if (len==1) {
        if(*s == *(s+1)) {  //cc => -1
            return -1;
        } else {
            return 0;       //ca => 0;
        }
    }
    if (len==0) return 0;   //a => 0;
    if (len<0)  return -1;  //空 => -1
    

    bool singel;
    for (int i=0; i<=len; i++) {
        //假定此值不重复
        singel = true;
        for (int j=0; j<=len; j++) {
            //当i=j时，不比较，跳过此次循环
            if (i==j) {
                continue;
            }
            //有等值时，singel为false,结束本层循环
            if (*(s+i) == *(s+j)) {
                singel = false;
                break;
            }
        }
        //此值循环一圈，未出现重复，返回其索引
        if (singel) {
            return i;
        }
        
    }
    return -1;
    
}
