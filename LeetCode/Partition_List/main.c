#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *partition(struct ListNode *head, int x);

void insert_next_val(struct ListNode *head, int next_val){
    struct ListNode *next = malloc(sizeof(int) + sizeof(struct ListNode));
    next->val = next_val;
    next->next = NULL;
    head->next = next; 

}

void print_ListNode(struct ListNode *head){
   struct ListNode *current = head;

   while(current != NULL){
       printf("%d\n", current->val);
       current = current->next;
   }



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

   int val = 3;

   while(i < length){
       insert_next_val(curr,values[i]);
       curr = head->next;
       i++;
   }

   print_ListNode(head);
   head = partition(head,val);
   print_ListNode(head);

   free(head);

   return 0;

}



struct ListNode *partition(struct ListNode *head, int x){
    struct ListNode *current = head;

    struct ListNode *dividerHead = NULL;
    struct ListNode *dividerIterator = NULL; //In case multiple of targets

    struct ListNode *leftHead = NULL;
    struct ListNode *rightHead = NULL;
    
    struct ListNode *leftIterator = NULL;
    struct ListNode *rightIterator = NULL;
    while(current->next != NULL){

    	if(current->val < x && leftHead == NULL){
	       leftHead = current;
	       leftIterator = current;
        } else if(current->val > x && rightHead == NULL){
	       rightHead = current;
	       rightIterator = current;
	    } else if(current->val == x && dividerHead == NULL){
	       dividerHead = current;
	       dividerIterator = current;
    	} else {
	       if(current->val < x){
		      leftIterator->next = current;
		      leftIterator = leftIterator->next;
	        }

	        if(current->val > x){
		        rightIterator->next = current;
		        rightIterator = leftIterator->next;
	        }

    	    if(current->val == x){
		        dividerIterator->next = current;
		        dividerIterator = leftIterator->next;
	        }
    	}

       current = current->next;
    }

    leftIterator->next = dividerHead;
    dividerIterator->next = rightIterator;

    return leftHead;

}
