#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>


int main(int argc,char *args[]){

    return 0;

}

//Remove Leading Spaces and Trailing spaces in string
char *removeStartEnd(char *s){

    int left = 0;
    int right = strlen(s)-1;
    int prevRight = strlen(s)-1;

    while(true){
        if(s[left] != ' ' && s[right] != ' '){
            break;
        }

        if(s[left] == ' '){
            left++;
        }

        if(s[right] == ' '){
            printf("HHlel\n");
            right--;
        }

    }

    s = s + left;           //Eliminate leading spaces
    
    if(prevRight != right){ //Eliminate trailing spaces
        s[right] = '\0';
    }

    return s;
}

//Remove multiple spaces between words
char *removeSpacePlus(char *s){

    char prev = 'a';
    char *string 
    
    for(int i = 0;i < strlen(s);i++){
        if(prev = ' '){
            prev = i-2; // -1 space before -1 actual letter == -2
            i = i-2;
            continue;
        }

        prev = str[i];

    }


    return s;
}

char* reverseWords(char* s) {
    if(strlen(s) == 0){
        return s;
    }

    s = removeStartEnd(s);
    s = removeSpacePlus(s);
/*
    int right = strlen(s)-1;

    for(int left = 0;left < strlen(s);left++){

        if(left == right){
            break;
        }

        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        right--;
    }
*/
    return s;
    
}


void print_array(int *array,int length){
    for(int i = 0;i<length;i++){
        printf("%d\n",array[i]);
    }   
}

