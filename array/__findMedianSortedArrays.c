//
//  __findMedianSortedArrays.c
//  LeetCode
//
//  Created by AIR on 2018/9/5.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * mergeSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    
    int *mergeArr = (int *)malloc(sizeof(int)*(nums1Size+nums2Size));
    int k=0;
    int i=0;
    int j=0;
    for (; i<nums1Size && j<nums2Size;) {
        if (nums1[i] == nums2[j]){
            mergeArr[k] = nums1[i];
            k++;
            mergeArr[k] = nums2[j];
            j++;
            i++;
        }else if (nums1[i] > nums2[j]) {
            mergeArr[k] = nums2[j];
            j++;
        }else {
            mergeArr[k] = nums1[i];
            i++;
        }
        k++;
    }
    
    if (j == nums2Size) {
        for (int m=0; m<nums1Size-1-i; m++) {
            mergeArr[k+m] = nums1[m];
        }
    }
    if (i == nums1Size) {
        for (int n=0; n<nums2Size-1-j; n++) {
            mergeArr[k+n] = nums2[n];
        }
    }
    
    
    return mergeArr;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    double median = 0;
    if (nums1Size == 0) {
        if (nums2Size %2 == 0) {
            median = (nums2[(nums2Size-1)/2] + nums2[(nums2Size+1)/2])/2.f;
        }else {
            median = nums2[nums2Size/2];
        }
    }
    
    if (nums2Size == 0) {
        if (nums1Size %2 == 0) {
            median = (nums1[(nums1Size-1)/2] + nums1[(nums1Size+1)/2])/2.f;
        }else {
            median = nums1[nums1Size/2];
        }
    }
    
    int *arr = mergeSortedArrays(nums1, nums1Size, nums2, nums2Size);
    int size = nums1Size + nums2Size;
    if (size%2) {
        median = arr[size/2];
    }else {
        median = (arr[(size-1)/2] + arr[(size+1)/2])/2.f;
    }
    
    return median;
}
