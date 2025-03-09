import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String [] args) {
        Solution sol = new Solution();

//        int[] nums = {0,1,2,4,5,7};
        //int[] nums = {0,2,3,4,6,8,9};
        int[] nums = {};

        System.out.println(sol.summaryRanges(nums).toString());



    }
}

class Solution {

    public List<String> summaryRanges(int[] nums) {
        List<String> range = new ArrayList<String>();

        if(nums.length == 0){
            return range;
        }

        int i = 0;
        int offset = 0; 
        int start = nums[i];
        int end = 0;
        boolean setStart = false;

        while(i < nums.length){
System.out.println("CHECKING " + nums[i]);
           if(setStart == false){
              start = nums[i];
System.out.println("New Start is " + start);
              offset = 1;
              end = nums[i];
              setStart = true;
              i++;
              continue;
            }

            if(start + offset == nums[i]) {
                end = nums[i];
            } else if(start == end) {
                    range.add("" + start);
                    i--;
                    setStart = false;                                        
            } else {
                    range.add(start + "->" + end);
                    i--;
                    setStart = false;
            }
            offset++;
            i++;
        }

        if(start == end){
            range.add("" + start);                                        
        } else {
            range.add(start + "->" + end);
        }

        return range;
        
    }
}
