//
//  __singleNumber.c
//  LeetCode
//
//  Created by AIR on 2018/9/5.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

/*说明：
    你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 */

//测试用例：[1,1,2,5,5]
int singleNumber(int* nums, int numsSize) {
    
    
    for (int i=0; i<numsSize; i++) {
        bool single = true;
        for (int j=0; j<numsSize; j++) {
            if ((i!=j) &&( nums[i] == nums[j])) {
                single = false;
                break;
            }
        }
        if (single == true) {
            return nums[i];
        }
    }
    return 0;
}
