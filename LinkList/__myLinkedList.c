//
//  __myLinkedList.c
//  LeetCode
//
//  Created by AIR on 2018/9/14.
//  Copyright © 2018年 com.TX.NordVPN. All rights reserved.
//

#include "__myLinkedList.h"


/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    
    MyLinkedList *list = malloc(sizeof(MyLinkedList));
    list -> next = NULL;
    list -> val = 0;
    return list;
    
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    
    int i = 0;
    while (obj != NULL) {
        
        if (i == index) {
            return obj->next->val;
        }
        obj = obj->next;
        i++;
    }
    return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    
    MyLinkedList *node = malloc(sizeof(MyLinkedList));
    node->val = val;
    node->next = obj->next;
    obj->next = node;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    
    MyLinkedList *node = malloc(sizeof(MyLinkedList));
    node->val = val;
    node->next = NULL;
    
    while (obj != NULL) {
        
        obj= obj->next;
        if (obj->next == NULL) {
            obj->next = node;
            break;
        }
    }
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    
    MyLinkedList *node = malloc(sizeof(MyLinkedList));
    int count = 0;
    while (obj!=NULL) {
        
        
        if (index == count) {
            
            node->next = obj->next;
            obj->next = node;
            node->val = val;
            break;
        }
        count++;
        
        obj = obj->next;
    }
    
    if (index > count) {
        return;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    
    int count = 0;
    while (obj != NULL) {
        
        if (index == count) {
            
            obj->val = obj->next->val;
            obj->next = obj->next->next;
            break;
        }
        count++;
        obj = obj->next;
    }
    
    if (index > count) {
        return;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    
    obj->val = 0;
    obj->next = NULL;
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */
