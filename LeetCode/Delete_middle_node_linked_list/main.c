#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>

struct ListNode {
         int val;
         struct ListNode *next;
};

int main(int argc,char *args[]){
    
    return 0;

}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {

    struct ListNode *node = head;
    struct ListNode *headcopy = head;
    int count = 0;

    while(head != NULL){
        head = head->next;
        count++;
    }

    node = headcopy;

    if(count == 1){
        return NULL;
    }

    if(count == 2){
        headcopy->next = NULL;
        return headcopy;
    }

    count = (double) count/2;
    

    for(int i = 0;i < count;i++){
        if(i == count-1){
            node->next = node->next->next;
        }
        node = node->next;
    }

    return headcopy;

    
}