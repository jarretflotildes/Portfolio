#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

void insert_next_val(struct ListNode *head, int next_val){
    struct ListNode *next = malloc(sizeof(int) + sizeof(struct ListNode));

    next->val = next_val;
    next->next = NULL;
    head->next = next; 

}

   
int main(int argc,char *args[]){
printf("Start\n");
   struct ListNode *head = malloc(sizeof(int) + sizeof(struct ListNode));
   head->val = 1;
   head->next = NULL;

   struct ListNode *curr = head;
   int i = 1;
   int length = 6;
   int values[6] = {1,4,3,2,5,2};

   while(i < length){
       insert_next_val(curr,values[i]);
       curr = head->next;
       i++;
   }

   free(head);

   return 0;

}



struct ListNode *partition(struct ListNode *head, int x){
    struct ListNode *current = head;

    struct ListNode *left = head;
    struct ListNode *right = head;

    while(current->next != NULL){


    }

    return head;

}
