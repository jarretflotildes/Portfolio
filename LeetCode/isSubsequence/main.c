#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
/*
Given two strings s and t, 
return true if s is a subsequence of t, 
or false otherwise.

A subsequence of a string is a new string that is formed from the 
original string by deleting some (can be none) of the characters 
without disturbing the relative positions of the remaining characters. 
(i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/
 
bool isSubsequence(char* s, char* t);

int main(int argc,char *args[]){


    char *s, *t;
    s = "abc"; 
    t = "ahbgdc";

    printf("%d",isSubsequence(s,t));

    return 0;

}






bool isSubsequence(char* s, char* t) {

    bool flag = false;
    size_t t_len = strlen(t);
    size_t s_len = strlen(s);
    int s_pointer = 0;

    if(strcmp(s,t) == 0){
        return true;
    }

    for(int i = 0;i<t_len;i++){
        if(s[s_pointer] == t[i]){
            s_pointer++;
        }

        if(s_pointer >= s_len){
            flag = true; 
            break;
        }

    }

    return flag;
}