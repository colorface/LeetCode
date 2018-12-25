//
//  __reverseBits.c
//  LeetCode
//
//  Created by AIR on 2018/10/10.
//  Copyright © 2018 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>
#include <math.h>

//颠倒给定的 32 位无符号整数的二进制位。

//进阶:
//如果多次调用这个函数，你将如何优化你的算法？
uint32_t reverseBits(uint32_t n) {
    int a[32] = {0};        //申请数组保留余数
    int i = 0;              //索引下标兼计数
    while (n > 0) {
        
        a[i] = n % 2;       //原数i为最低位，新数i为最高位
        n = n / 2;
        i++;
    }
    
    uint32_t rev = 0;
    for (int j=0; j<i; j++) {
        if (a[j] == 0) {
            continue;
        }
        rev += pow(2, 31-j);
    }
    return rev;
}
