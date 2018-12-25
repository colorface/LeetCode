//
//  __maxProfit_0.c
//  LeetCode
//
//  Created by AIR on 2018/9/10.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>

int maxProfit(int *prices, int pricesSize) {
    
    int tmp = 0;
    int max = 0;
    for (int i=0; i<pricesSize; i++) {
        
        for (int j=i+1; j<pricesSize; j++) {
            
            tmp = prices[j] - prices[i];
            
            if (max < tmp) {
                max = tmp;
            }
        }
    }
    return max;
}
