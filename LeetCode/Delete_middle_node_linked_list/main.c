#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>

bool canJump(int* nums, int numsSize);
int canJumpHelper(int *nums,int numsSize,int currElem);
void print_array(int *array,int length);

bool canJumpGreed(int *nums,int numsSize);

int main(int argc,char *args[]){
    int array4[] = {2,5,0,0};
    int array3[] = {2,3,1,1,4};
    int array2[] = {1,2,3};
    int array[] = {2,0,0};

    int *pointer = array4;
    int length = 4;
    print_array(array4,length);
//    bool can = canJump(pointer,length);
    bool can = canJumpGreed(pointer,length);
    printf("Can jump is %d\n",can);

    return 0;

}

bool canJump(int* nums, int numsSize){
    
    int currElem = 0;
    int jump = 0;
    bool help = canJumpHelper(nums,numsSize,currElem);
    
    return help;

}

int canJumpHelper(int *nums,int numsSize,int currElem){
    bool jump_possible = false;

    if(currElem >= numsSize){
       return false;
    }
    
    //Reached 
    if(currElem == numsSize-1){
        return true;
    }
    
    //can't move, but last elem can be 0 so check after reached
    if(nums[currElem] == 0){
       return false;
    }

    for(int i = 0;i<nums[currElem];i++){
        
        jump_possible = canJumpHelper(nums,numsSize,currElem+1+i);
        if(jump_possible == true){
            break;
        }
    }

    return jump_possible;

}

bool canJumpGreed(int *nums,int numsSize){

    int position = 0;
    bool canJump = false;

    while(1){
        int jump = nums[position];

        while(jump > 0){
           position = position + jump;

           if(nums[position] == 0){
                jump--;
           } else {
              break;
           }
        }

        if(position >= numsSize-1){
            canJump = true;
            break;
        }

        if(position >= numsSize){
            break;
        }

        if(jump == 0){
            break;
        }


    }

    return canJump;
}



void print_array(int *array,int length){
    for(int i = 0;i<length;i++){
        printf("%d\n",array[i]);
    }   
}

