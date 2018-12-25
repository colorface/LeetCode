
//  __mergeSortedArr.c
//  LeetCode
//
//  Created by AIR on 2018/9/14.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>

void mergeSortedArr(int* nums1, int m, int* nums2, int n) {
    
    for (int i=0; i<n; i++) {           // 类似抓扑克牌排序
        
        int cur = nums2[i];                 // 右手抓到一张扑克牌
        int j = m+i-1;                  // 拿在左手上的牌总是排序好的
        int count = 0;
        while (j>=0) {                  // 将抓到的牌与手牌从右向左进行比较
            
            if (nums1[j] > cur) {
                j--;
                count++;
                continue;
            }
            
            nums1[j+1] = nums2[i];// 如果该手牌比抓到的牌大，就将其右移
            
            for (int k=0; k<count; k++) {
                nums1[j+1+k] = nums1[j+1+k+1];
            }
        }
        nums1[j] = cur;                   // 直到该手牌比抓到的牌小(或二者相等)，
        // 将抓到的牌插入到该手牌右边
        //(相等元素的相对次序未变，所以插入排序是稳定的)
    }
}
