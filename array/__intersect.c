//
//  __intersect.c
//  LeetCode
//
//  Created by AIR on 2018/9/5.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 //两个数组的交集2
 
 测试用例:    [1,2,2,1],[2,2]  => [2,2]
            [4,9,5],[9,4,9,8,4] =>[4,9]
            [1,5,8,9],[2,5,9]   =>[5,9]
            [1,2],[2,1]         =>[1,2]
 
    说明：    存在相同元素即为交集元素，找出所有交集元素
            输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致
            我们可以不考虑输出结果的顺序。
 */

//排序算法，选择排序法
void sortArr(int *nums, int numsSize){
    
    int tmp = 0;
    for (int i=0; i<numsSize; i++) {
        for (int j=i+1; j<numsSize; j++) {
            if (nums[i] > nums[j]) {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    
    sortArr(nums1, nums1Size);
    sortArr(nums2, nums2Size);
    
    int maxSize = nums1Size > nums2Size ? nums1Size : nums2Size;
    int minSize = nums1Size > nums2Size ? nums2Size : nums1Size;
    int *maxNum = nums1Size > nums2Size ? nums1 : nums2;
    int *minNum = nums1Size > nums2Size ? nums2 : nums1;
    
    int* arr = (int *)malloc(sizeof(int)*minSize);
    int k = 0;  //记录新数组保存位置索引
    int j = 0;  //较大数组的索引
    for (int i=0; i<minSize; i++) {
        for (;j<maxSize;) {
            if (minNum[i] == maxNum[j]){
                arr[k] = minNum[i];
                k++;//存在相同元素，各向后一位
                j++;
                break;
            }else if (minNum[i] > maxNum[j]) {
                j++;  //较小元素，取后一位
            }else {
                break;//较小元素，取后一位
            }
        }
    }
    
    
    
    *returnSize = k;
    
    return arr;
    
}
