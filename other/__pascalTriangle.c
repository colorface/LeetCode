//
//  __pascalTriangle.c
//  LeetCode
//
//  Created by AIR on 2018/10/10.
//  Copyright © 2018 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


/*
 输入: 5
 输出:
 [
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
 ]
 
 */
int** generate(int numRows, int** columnSizes) {
    
    
    if (numRows == 1) {
        int **arr = malloc(sizeof(int));
        arr[0][0] = 1;
        return arr;
    }
    
    if (numRows == 2) {
        int **arr = malloc(sizeof(int)*4);
        arr[0][0] = 1;
        arr[1][0] = 1;
        arr[1][1] = 1;
        return arr;
    }
    
    for (int i=0; i<numRows; i++) {
        
        for (int j=0; j<numRows; j++) {
            
            
        }
    }
}
