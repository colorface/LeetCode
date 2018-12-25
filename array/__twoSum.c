//
//  __twoSum.c
//  LeetCode
//
//  Created by AIR on 2018/9/5.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>

/*
 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
 你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
 */
//测试用例:[2,7,11,15]
int *twoSum(int *nums, int numsSize, int target) {
    
    static int arr[2];
    
    for (int i=0; i<numsSize; i++) {
        for (int j=1+i; j<numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                arr[0] = i;
                arr[1] = j;
                break;
            }
        }
    }
    return arr;
}
