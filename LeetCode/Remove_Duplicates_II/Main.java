import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String [] args) {
        Solution sol = new Solution();

        int[] nums = {0,1,1,2,2,4,5,7};
        //int[] nums = {0,2,3,4,6,8,9};

        System.out.println(sol.removeDuplicates(nums));


    }
}

class Solution {
    public int removeDuplicates(int[] nums) {
        int current = 1;
        int previous = 0;

        for(int i = 2; i < nums.length; i++){

            //current and previous are same
            if(nums[current] == nums[previous] && nums[i] == nums[current]){ 
                //do nothing
            }

            //current and previous are different
            else {
                previous = current;
                current++;
                nums[current] = nums[i];
            }

        }

        current++; //actual amount

        return current;

        
        
    }
}