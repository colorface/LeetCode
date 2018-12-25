//
//  __maxSubArray.c
//  LeetCode
//
//  Created by AIR on 2018/9/10.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>


int maxSubArray(int *nums, int numsSize){
    
    int max = 0;
    int sum;
    int once = 1;
    for (int i=0; i<numsSize; i++) {
        if (once && nums[i] < 0) {
            once = 0;
            continue;
        }
        
        sum = nums[i];
        for (int j=i+1; j<numsSize; j++) {
            
            sum += nums[j];
            if (max < sum) {
                max = sum;
            }
        }
        sum = 0;
    }
    return max;
}
