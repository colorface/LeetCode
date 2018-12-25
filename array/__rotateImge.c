//
//  __rotateImge.c
//  LeetCode
//
//  Created by AIR on 2018/9/6.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>

//旋转图像
/*
 给定一个 n × n 的二维矩阵表示一个图像。
 将图像顺时针旋转 90 度。
 说明：你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
 */
/*
 [1,2,3]        [7,4,1]
 [4,5,6]   ==>  [8,5,2]
 [7,8,9]        [9,6,3]
*/

void rotateImge(int** matrix, int matrixRowSize, int *matrixColSizes) {
    int tmp = 0;
    for (int i=0; i<matrixRowSize; i++) {
        for (int j=i+1; j<matrixRowSize; j++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    
    for (int i=0; i<matrixRowSize; i++) {
        for (int j=0; j<matrixRowSize/2; j++)
        {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixRowSize-j-1];
            matrix[i][matrixRowSize-j-1] = tmp;
        }
    }
    *matrixColSizes = matrixRowSize;
}
