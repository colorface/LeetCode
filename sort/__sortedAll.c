//
//  __sortedAll.c
//  LeetCode
//
//  Created by AIR on 2018/9/13.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>

/*
 
汇总：
 
① 冒泡排序
    鸡尾酒排序
② 选择排序
③ 插入排序
    二分插入排序
    希尔排序
④ 归并排序
⑤ 堆排序
⑥ 快速排序
 
*/

void swapInt(int *a, int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
