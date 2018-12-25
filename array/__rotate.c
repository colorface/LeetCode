//
//  __rotate.c
//  LeetCode
//
//  Created by AIR on 2018/9/5.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>

//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//测试用例:
/*
 输入: [1,2,3,4,5,6,7] 和 k = 3
 输出: [5,6,7,1,2,3,4]
 解释:
 向右旋转 1 步: [7,1,2,3,4,5,6]
 向右旋转 2 步: [6,7,1,2,3,4,5]
 向右旋转 3 步: [5,6,7,1,2,3,4]
 */
//[-1] k=2
//[1,2] k=3

int *reverse(int *nums, int numsSize) {
    for (int i=0; i<numsSize/2; i++) {
        int tmp = nums[i];
        nums[i] = nums[numsSize-1-i];
        nums[numsSize-i-1] = tmp;
    }
    return nums;
}

void rotate(int* nums, int numsSize, int k) {
    
    if (numsSize == 0) return;
    if (k == 0) return;
    if (k > numsSize) k = k - numsSize;
    
    reverse(nums, numsSize-k);
    //sizeof(int) = 4;
    //nums + k 为第k个元素的指针
//    printf("%lu",sizeof(int));
//    printf("%p",nums);printf("\n");
//    printf("%p",nums+1);printf("\n");
//    printf("%p",nums+2);printf("\n");
//    printf("%p",nums+2*sizeof(int));printf("\n");
//    printf("%p",nums+numsSize-k+1);printf("\n");
    
    reverse(nums+numsSize-k, k);
    reverse(nums, numsSize);
}
