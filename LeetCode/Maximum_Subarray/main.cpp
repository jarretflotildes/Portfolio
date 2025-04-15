class Solution {
    public:
    
        //1 <= low <= high <= 10^4
        int countDigits(int num){
            int val = 0;
    
            if(num < 10){
                val = 1;
            } else if(num < 100){
                val = 2;
            } else if(num < 1000){
                val = 3;
            } else if(num < 10000){
                val = 4;
            } else if(num < 100000){
                val = 5;
            }
    
            return val;
        }
    
        int addDigits(int num){
            int sum = 0;
            int digits = countDigits(num);
    
            for(int i = 0;i<digits;i++){
                int foundDigit = num%10;
                sum = sum + foundDigit;
                num = num/10;
            }
    
            return sum;
        }
    
        int countSymmetricIntegers(int low, int high) {
            //Numbers with an odd number of digits are never symmetric.
            int count = 0;
    
            for(int i = low;i<=high;i++){
                int digits = countDigits(i);
                if(digits%2 != 0){
                    continue;
                }
                int left = i;
    
                for(int j = 0;j<digits/2;j++){
                    left = left/10;
                }
    
                int right = 0;
                int temp = i;
    
                for(int j = 0; j<digits/2;j++){
                    int foundDigit = temp%10;
                    for(int k = 0;k<j;k++){
                        foundDigit *= 10;
                    }
                    right = right + foundDigit;
                    temp = temp/10;
                }
    
                if(addDigits(left) == addDigits(right)){
                    printf("SUM LEFT %d SUM RIGHT %d\n",addDigits(left),addDigits(right));
     //printf("%d\n",i);
                    count++;
                }
    
            }
    
            return count;
            
        }
    
    
    };