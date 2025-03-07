import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String [] args) {
        Solution sol = new Solution();

        int[] nums = {0,1,2,4,5,7};
        System.out.println(sol.summaryRanges(nums).toString());



    }
}

class Solution {

    public List<String> summaryRanges(int[] nums) {
        List<String> range = new ArrayList<String>();
        int i = 0;
        int start = nums[i];
        int end = 0;
        boolean setStart = false;

        while(i < nums.length){
           if(setStart == false){
              start = nums[i];
              setStart = true;
              i++;
              continue;
            }

            if(start + 1 == nums[i]){
                end = nums[i];
            } else {
                                
            }



        }




        return range;
        
    }
}
