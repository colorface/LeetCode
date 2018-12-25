//
//  __plusone.c
//  LeetCode
//
//  Created by AIR on 2018/9/6.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
//最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
//你可以假设除了整数 0 之外，这个整数不会以零开头。

//测试用例:
//[1,2,3] , [9]
int *plusone(int *digits, int digitsSize, int *returnSize)
{
    
    int *ds = (int *)malloc(sizeof(int*)*digitsSize);
    
    for (int i=0; i<digitsSize; i++) {
        ds[i] = digits[i];
    }
    
    int i = digitsSize-1;
    while (i>=0) {
        
        if (digits[i] < 9) {
            ds[i] += 1;
            *returnSize = digitsSize;
            break;
        }else {
            ds[i] = 0;
        }
        
        if (i == 0) {
            ds = realloc(ds, sizeof(int*)*(digitsSize+1));
            ds[0] = 1;
            ds[digitsSize] = 0;
            *returnSize = digitsSize+1;
            break;
        }
        
        i--;
    }
    return ds;
    
}
