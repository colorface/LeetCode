//
//  __removeDuplicates.c
//  LeetCode
//
//  Created by AIR on 2018/9/5.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>

//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

//测试用例：[0,0,1,1,2,2,3,3,4,5,5,6];

int removeDuplicates(int *nums, int numsSize) {
    
    int i = 1;
    for (int j=1; j<numsSize; j++) {
        if (nums[j] != nums[i-1]) {
            nums[i] = nums[j];
            i++;
        }
//        for (int k=0;k<numsSize;k++){
//            printf("%d",nums[k]);
//
//        }
//        printf("\n");
    }
    return (i > numsSize)? numsSize : i;
}
