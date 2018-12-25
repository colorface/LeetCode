//
//  __isValidSudoku.c
//  LeetCode
//
//  Created by AIR on 2018/9/6.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool isValidCol(char **board, int boardRowSize, int boardColSize){
    int i, j;
    int arr[boardColSize];
    memset(arr, 0, boardColSize*sizeof(int));
    for(i = 0; i < boardRowSize; i++){
        for(j = 0; j < boardColSize; j++){
            if(board[i][j] != '.')
                arr[board[i][j]-'0'-1]++;
        }
        for(j = 0; j < boardColSize; j++){
            if(arr[j] >= 2)
                return false;
        }
        memset(arr, 0, boardColSize*sizeof(int));
    }
    return true;
}
bool isValidRow(char** board, int boardRowSize, int boardColSize){
    int i, j;
    int arr[boardRowSize];
    memset(arr, 0, boardRowSize*sizeof(int));
    for(i = 0; i < boardRowSize; i++){
        for(j = 0; j < boardColSize; j++){
            if(board[j][i] != '.')
                arr[board[j][i]-'0'-1]++;
        }
        for(j = 0; j < boardRowSize; j++){
            if(arr[j] >= 2)
                return false;
        }
        memset(arr, 0, boardRowSize*sizeof(int));
    }
    return true;
}
bool isValidArr(char** board, int boardRowSize, int boardColSize){
    int i, j, n, m;
    int arr[boardRowSize];
    memset(arr, 0, boardColSize*sizeof(int));
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            for(m = 0; m < 3; m++){
                for(n = 0; n < 3; n++){
                    if(board[i*3+m][j*3+n] != '.')
                        arr[board[i*3+m][j*3+n]-'0'-1]++;
                }
            }
            for(m = 0; m < boardRowSize; m++){
                if(arr[m] >= 2)
                    return false;
            }
            memset(arr, 0, boardRowSize*sizeof(int));
        }
    }
    return true;
}


bool isValidSudoku(char **board, int boardRowSize, int boardColSize) {
    return isValidCol(board,boardRowSize,boardColSize) && isValidRow(board,boardRowSize, boardColSize) && isValidArr(board,boardRowSize,boardColSize);
}
