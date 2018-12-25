//
//  __mergeTwoLists.c
//  LeetCode
//
//  Created by AIR on 2018/9/14.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    
    struct ListNode *merge = (struct ListNode *)malloc(sizeof(struct ListNode));
    
    while (l1 && l2) {
        
        if (l1->val >= l2->val) {
            merge->val = l2->val;
            merge->next = l2->next;
            l2 = l2 ->next;
            
            if (!l2) {
                merge->val = l2 -> val;
                merge->next = l1;
            }
        }
        if (l1 ->val < l2->val) {
            merge->val = l1->val;
            merge->next = l1->next;
            l1 = l1->next;
            
            if (!l1) {
                merge->val = l1 -> val;
                merge->next = l2;
            }
        }
        
    }
    merge->next = NULL;
    return merge;
}
