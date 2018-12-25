//
//  __selectionSort.c
//  LeetCode
//
//  Created by AIR on 2018/9/13.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>

// name -------------选择排序
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(n^2)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定

/*
 选择排序也是一种简单直观的排序算法。
 
 它的工作原理很容易理解：初始时在序列中找到最小（大）元素，放到序列的起始位置作为已排序序列；
 然后，再从剩余未排序元素中继续寻找最小（大）元素，放到已排序序列的末尾。
 以此类推，直到所有元素均排序完毕。
 
 注意选择排序与冒泡排序的区别：
 冒泡排序通过依次交换相邻两个顺序不合法的元素位置，从而将当前最小（大）元素放到合适的位置；
 而选择排序每遍历一次都记住了当前最小（大）元素的位置，最后仅需一次交换操作即可将其放到合适的位置。
 
 说明：选择排序是不稳定的排序算法，不稳定发生在最小元素与a[i]交换的时刻。
 eg:{5,8,5,2,9}一次选择的最小元素是2，然后把2和第一个5进行交换，从而改变了两个元素5的相对次序。
 */

void swapInt(int *a, int i, int j);

void selectionSort(int *a, int len) {
    
    int index;                          //记录元素索引
    for (int i=0; i<len-1; i++) {       //i为已排序列的末尾
        
        index = i;
        
        for (int j=i+1; j<len; j++) {   //未排序序列
            
            if (a[j] < a[index]) {
                index = j;              //找出未排序序列的最小值
            }
        }
        
        if (index != i) {
            swapInt(a, i, index);       //放到已排序序列的末尾，
                                        //该操作很有可能把稳定性打乱，
                                        //所以选择排序是不稳定的排序算法
        }
    }
}
