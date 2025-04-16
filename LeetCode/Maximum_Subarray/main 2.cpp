class Solution {
    public:
    
        int minSubArrayLen(int target, vector<int>& nums) {
            int length = nums.size();
    
            int left = 0;
            int sum = nums[0];
            int runningLength = 1;
            bool reached = false;
    
            if(nums[0] >= target){
                return 1;
            }
    
            for(int right = 1;right < nums.size();right++){
                sum += nums[right];
                runningLength = right - left + 1;
    cout << "sum " << sum << " in " << runningLength << endl;
    
                if(sum >= target){
                    if(runningLength <= length){
                        length = runningLength;
                        reached = true;
                    }
                    sum -= nums[left];
                    sum -= nums[right];
                    right--;
                    runningLength--;
                    left++;
                }
           
            }
             
            if(!reached){
                length = 0;
            }
    
    
            return length;
            
        }
    };