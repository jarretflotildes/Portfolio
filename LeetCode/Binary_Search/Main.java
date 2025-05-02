class Solution {
    public int searchInsert(int[] nums, int target) {

        int half = nums.length/2;
        int index = 0;

        if(nums[half] == target){
            return half;
        }

        if(nums[half] > target){
            for(int i = 0;i < half;i++){
                if(i == 0 && nums[0] > target){
                    index = 0;
                    break;
                }
                if(nums[i] == target){
                    index = i;
                    break;
                }

                if(nums[i] > target){
                    break;
                }

                index++;
            }
        } else {
            index = half;
            for(int i = half;i < nums.length;i++){
                if(i == half && nums[half] > target){
                    break;
                }
                if(nums[i] == target){
                    index = i;
                    break;
                }
                if(nums[i] > target){
                    break;
                }

                index++;
            }

        }

        return index;

        
    }
}