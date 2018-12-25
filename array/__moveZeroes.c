//
//  __moveZeroes.c
//  LeetCode
//
//  Created by AIR on 2018/9/6.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>

//测试用例：[0，1，0，3，12],[0,0,1]

void moveZeroes(int *nums,int numsSize) {
    
    int j=0;//记录0后元素交换次数（循环次数）
    int n=0;//记录0出现的次数,用于索引赋值
    int m=0;//累积记录数组不为0的个数
    for (int i=numsSize-1; i>=0; i--) {
        if (nums[i] == 0) {
            //累积记录交换次数
            m += j;
            //交换
            for (int k=0; k<m; k++) {
                nums[i+k] = nums[i+1+k];
            }
            //索引赋值
            nums[numsSize-n-1] = 0;
            //清除当前不为0个数
            j = 0;
            //记录0出现的次数
            n++;
        }else {
            //重新保存0后不为1个数
            j++;
        }
    }
}
