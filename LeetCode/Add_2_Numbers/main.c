#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char *addBinary(char *a, char *b);
int binary_to_int(char *binary);
char *int_to_binary(int number);
    
int main(int argc,char *args[]){

    char *a = "1";
    char *b = "11";

//    printf("%s = %d\n",a,binary_to_int(a));
//    printf("%s = %d\n",b,binary_to_int(b));

    printf("In binary this is %s\n",addBinary(a,b));

    return 0;

}

char *addBinary(char *a, char *b){
    int num_a = binary_to_int(a);
    int num_b = binary_to_int(b);
    return int_to_binary(num_a+num_b);
}


int binary_to_int(char *binary){
    int position = strlen(binary);
//printf("Length is %d\n",position);
    int translated = 0; 

    for(int i = 0; i<position;i++){
        if(binary[i] == '1'){
            int number = pow((double)2,(double)position-i-1);
            translated += number;
//printf("%c = %d\n",binary[i],number);
        } else {
//printf("%c = %d\n",binary[i],0);
        }
    }

    return translated;

}

char *int_to_binary(int number){
    int count = 0;
    int count2 = 0;
    int temp = number;

    while(temp > 0){
        temp = temp/2;
        count++;
    }
//    count--;
//    char *binary = malloc(sizeof(count)*4 + 1);
char *binary = "";

    while(number > 0){
        int temp = number;
        char *num = malloc(sizeof(count)*4 + 1);
        temp = temp%2;
        if(temp == 1){
printf("Current number is %d = 1\n",number);
//            strcat(binary,"0");
            strcat(num,"1");
            strcat(num,binary);
            binary = strdup(num);
        } else {
printf("Current number is %d = 0\n",number);
//            strcat(binary,"0");
            strcat(num,"0");
            strcat(num,binary);
            binary = strdup(num);
        }

        //if perfect then already done and rest is 0
        if(number % (int)pow((double)2,(double)count)==0){
            for(int i = count2;i<count;i++){
               strcat(binary,"0");
            }
            break;
        }

        number = number/2;
        count2++;
        free(num);
    }

    return binary;

}
 