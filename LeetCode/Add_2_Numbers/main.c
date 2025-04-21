#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

    
int main(int argc,char *args[]){


    return 0;

}

void println(char *string,int value){
    printf("%s %d\n",string,value);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode *l1_node = l1;
    int l1_val = 0;
    int l1_digits = 0;

    struct ListNode *l2_node = l2;
    int l2_val = 0;
    int l2_digits = 0;

    struct ListNode *head = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode *l3 = head;

    int carry = 0;

    if(l1_node != NULL && l2_node != NULL){
        int val = l1_node->val + l2_node->val + carry;
        if(val > 9){
            carry = val / 10;
            val = val%10;
        } else {
            carry = 0;
        }
        l3->val = val;
        l3->next = NULL;
        l1_node = l1_node->next;
        l2_node = l2_node->next;
    } else if(l1_node != NULL){
        l3->val = l1_node->val;
        l3->next = NULL;
        l1_node = l1_node->next;
    } else if(l2_node != NULL){
        l3->val = l2_node->val;
        l2_node = l2_node->next;
    }

    while(l1_node != NULL || l2_node != NULL){
        struct ListNode *node = (struct ListNode*) malloc(sizeof(struct ListNode));
        if(l1_node != NULL && l2_node != NULL){
            int val = l1_node->val + l2_node->val + carry;
            if(val > 9){
                carry = val / 10;
                val = val%10;
            } else {
                carry = 0;
            }
            node->val = val;
            node->next = NULL;
            l3->next = node;
            l3 = l3->next;
            l1_node = l1_node->next;
            l2_node = l2_node->next;
        } else if(l1_node != NULL){
            int val = l1_node->val + carry;
            if(val > 9){
                carry = val / 10;
                val = val % 10;
            } else {
                carry = 0;
            }
            node->val = val;
            node->next = NULL;
            l3->next = node;
            l3 = l3->next;
            l1_node = l1_node->next;
        } else if(l2_node != NULL){
            int val = l2_node->val + carry;
            if(val > 9){
                carry = val / 10;
                val = val % 10;
            } else {
                carry = 0;
            }
            node->val = val;
            node->next = NULL;
            l3->next = node;
            l3 = l3->next;
            l2_node = l2_node->next;
        }

    }

    while(carry > 0){
        struct ListNode *node = (struct ListNode*) malloc(sizeof(struct ListNode));
        int temp = carry%10;
        carry = carry/10;
        node->val = temp;
        node->next = NULL;
        l3->next = node;
        l3 = l3->next;
    }

    return head;
}