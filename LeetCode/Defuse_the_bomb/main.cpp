class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
    
            if(nums.size() == 0){
                return 0;
            }
    
            if(nums.size() == 1){
                return nums[0];
            }
    
            int highestSum = nums[0];
            int runningSum = 0;
    
            for(int i = 0;i<nums.size();i++){
                runningSum = runningSum + nums[i];
                if(runningSum < nums[i]){
                    runningSum = nums[i];
                }
    
                if(runningSum > highestSum){
                    highestSum = runningSum;
                }
                
            }
    
            return highestSum;
            
        }
    };