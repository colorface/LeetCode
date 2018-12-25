//
//  __hammingWeight.c
//  LeetCode
//
//  Created by AIR on 2018/10/10.
//  Copyright © 2018 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>

//位1的个数
//输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数
int hammingWeight(uint32_t n) {
    
    int count = 0;
    
    while (n > 0) {
        
        count += n % 2;
        n = n / 2;
    }
    return count;
}

//汉明距离
//两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

int hammingDistance(int x, int y) {
    
    int count = 0;
    while (x > 0 || y > 0) {
        if (x % 2 != y % 2) {
            count++;
        }
        x = x / 2;
        y = y / 2;
    }
    return count;
}
