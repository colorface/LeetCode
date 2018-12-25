//
//  __longestCommonPrefix.c
//  LeetCode
//
//  Created by AIR on 2018/9/13.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 最长公共前缀：编写一个函数来查找字符串数组中的最长公共前缀。
 如果不存在公共前缀，返回空字符串 ""。
 测试用例：
 输入: ["flower","flow","flight"]
 输出: "fl"
 
 输入: ["dog","racecar","car"]
 输出: ""
 解释: 输入不存在公共前缀。
 
 说明：所有输入只包含小写字母 a-z
 */


char* longestCommonPrefix(char** strs, int strsSize) {
    
    //当二维数组为【】时，返回空数组
    if (strsSize == 0) {
        char *a = (char*)malloc(sizeof(char));
        memset(a, 0, 1);
        return a;
    }
    //长度为1时，返回strs[0]数组，即*strs
    if (strsSize == 1) {
        return *strs;
    }
    
    char c = '\0';
    int count = 0;      //用于记录遍历各字串的进度，当count==strsSize时，确定当前字符为
                        //公共前缀
    int i = 0;          //代表行数
    int j = 0;          //代表列数
    int flag = 1;       //跳出循环增加的变量
    
    while (strs[i][j] != '\0' && flag) {
        
        c = strs[i][j]; //拿出第一个字串的各元素
        
        //遍历条件，行数小于字串长度
        while (i < strsSize) {
            
            //各字串遍历当前列字符 当等于c时，count++;
            if (strs[i][j] == c) {
                
                count++;
                if (count == strsSize) {
                    //各字符均含有c时，设置各变量
                    i=0;            //行数重置为首行
                    count=0;        //计数清0
                    j++;            //移到下一列
                    
                    break;          //跳出本层循环
                }
            }else {
                //退出循环，flag辅助用于退出外层循环
                flag = 0;
                break;
            }
            i++;    //移到下一行
        }
    }
    //当count ！= strsSize 即表示j=0，表示首列不全为c
    if (j == 0) {
        return "";
    }
    char *p = (char *)malloc(sizeof(char)*j);
    for (int k=0; k<j; k++) {
        p[k] = strs[0][k];
    }
    p[j] = '\0';
    return p;
}
