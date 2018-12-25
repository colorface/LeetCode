//
//  __bubbleSort.c
//  LeetCode
//
//  Created by AIR on 2018/9/13.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>

// name -------------冒泡排序
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- 如果能在内部循环第一次运行时,使用一个旗标来表示有无需要交换的可能,可以把最优时间复杂度降低到O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
/*
 冒泡排序是一种极其简单的排序算法，也是我所学的第一个排序算法。它重复地走访过要排序的元素，
 依次比较相邻两个元素，如果他们的顺序错误就把他们调换过来，直到没有元素再需要交换，排序完成。
 这个算法的名字由来是因为越小(或越大)的元素会经由交换慢慢“浮”到数列的顶端。
 
 冒泡排序算法的运作如下：
 ①比较相邻的元素，如果前一个比后一个大，就把它们两个调换位置。
 ②对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
 ③针对所有的元素重复以上的步骤，除了最后一个。
 ④持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
 
 说明文字：鸡尾酒排序是冒泡排序的一种改良，但是在乱数序列的状态下，这两种泡面排序效率很差，
 eg:{2,3,4,5,1} 此序列用鸡尾酒排序只需要访问一次序列就可以完成排序，但如果使用冒泡排序则需要四次
 */


void swapInt(int *a, int i, int j);

void bubbleSort(int *a, int len) {      //每次最大元素就像气泡一样“浮”到数组的最后
    for (int i=0; i<len-1; i++) {       //循环总量控制
        for (int j=0; j<len-i-1; j++) { //
            
            if (a[j] > a[j+1]) {        //依次比较相邻的元素，最大的元素后移
                //如果条件变成>= ，则为不稳定排序
                swapInt(a, j,j+1);
            }
        }
        //下位最小元素冒泡法
        //        for (int j=len-1; j>i; j--) {
        //
        //            if (a[j] < a[j-1]) {
        //                swapInt(a, j,j-1);
        //            }
        //        }
        for (int k=0; k<len; k++) {
            printf("%d",a[k]);
        }
        printf("\n");
    }
}

// name -------------鸡尾酒排序
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- 如果序列在一开始已经大部分排序过的话,会接近O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定

/*
 鸡尾酒排序,冒泡排序改良，定向冒泡排序算法
 */
void cocktailSort(int *a, int len) {
    
    int left = 0;
    int right = len - 1;                    //初始化边界
    
    while (left < right) {
        for (int i=left; i<right; i++) {    //前半轮，将最大元素放到后边
            if (a[i] > a[i+1]) {
                swapInt(a, i, i+1);
            }
        }
        
        right--;
        
        for (int j=right; j>left; j--) {    //后半轮，将最小元素放到前边
            if (a[j] < a[j-1]) {
                swapInt(a, j, j-1);
            }
        }
        left++;
    }
}