import java.util.List;
import java.util.ArrayList;

public class Main {

    public static void main(String [] args) {
        Solution solution = new Solution();
        int nums[] = {-1,0,1,2,-1,-4};
        for(int i = 0;i<nums.length;i++){
          System.out.print(nums[i] + " ");
        }
        System.out.println();

        solution.threeSum(nums);
    }

}

class Solution {
  /* 
  Given an integer array nums, return all the triplets 
  [nums[i], nums[j], nums[k]] such that 
  1. i != j, i != k, and j != k, 
  2. nums[i] + nums[j] + nums[k] == 0.

  Notice that the solution set must not contain duplicate triplets.
  Example 1:
  Input: nums = [-1,0,1,2,-1,-4]

-1 0 
 0 1
 1 2 
-1 -4 

  Output:       [[-1,-1,2],[-1,0,1]]
  Explanation: 
  nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
  nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
  nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
  The distinct triplets are [-1,0,1] and [-1,-1,2].
  Notice that the order of the output and the order of the triplets does not matter.
  */

  //first attempt
  public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> threeSum = new ArrayList<List<Integer>>();

        ArrayList<Integer> positive = new ArrayList<Integer>();
        ArrayList<Integer> negative = new ArrayList<Integer>();
        ArrayList<Integer> zero = new ArrayList<Integer>();

        if(nums.length < 3){
          return threeSum;
        }

        for(int i = 0; i < nums.length;i++){
          if(nums[i] > 0){
            positive.add(i);
          } else if(nums[i] < 0){
            negative.add(i);
          } else {
            zero.add(i);
          }
        }

        if(negative.isEmpty() == true || positive.isEmpty() == true){
          return threeSum;
        }

        threeSum = pos_i(positive, negative, zero, nums, threeSum);
        threeSum = normalSearch(positive, negative, zero, nums, threeSum);
//        threeSum = neg_i(positive, negative, zero, nums, threeSum);

System.out.println(threeSum.toString());
        return threeSum;
    
  }

  private List<List<Integer>> pos_i(ArrayList<Integer> positive,ArrayList<Integer> negative, ArrayList<Integer> zero, int[] nums,
                                    List<List<Integer>> threeSum){
        int i = 0;
        int j = 0;
        int k = 0;

        if(positive.size() < 2){
          return threeSum;
        }

        int first_index = positive.get(0);
        int second_index = positive.get(1);
        int third_index = 0;

        while(true){
           int sum = nums[first_index] + nums[second_index];
           third_index = negative.get(0);
           for(int l = 0;l<negative.size();l++){
              if(sum + third_index == 0){
                    List<Integer> temp = new ArrayList<Integer>();
                    temp.add(nums[first_index]);
                    temp.add(nums[second_index]);
                    temp.add(nums[zero.get(0)]);
                    threeSum.add(temp);
                    break;
                 }
           }

           j++;
           if(j > positive.size()-1){
             i++;
             j = i + 1;
           }

           if(i >= positive.size()-1){
  System.out.println(nums[i]);
             break;
           }

           first_index = positive.get(i);
           second_index = negative.get(j);
        }

        return threeSum;
      }

    private List<List<Integer>> neg_i(ArrayList<Integer> positive,ArrayList<Integer> negative, ArrayList<Integer> zero, int[] nums,
                                    List<List<Integer>> threeSum){
        int i = 0;
        int j = 0;
        int k = 0;

        if(negative.size() < 2){
           return threeSum;
        }

        int first_index = positive.get(0);
        int second_index = positive.get(1);
        int third_index = 0;

        while(true){
           int sum = nums[first_index] + nums[second_index];
           third_index = positive.get(0);
              for(int l = 0;l<negative.size()-1;l++){
                 if(positive.get(l) == l){
                    continue;
                 }
                 if(sum + third_index == 0){
                    List<Integer> temp = new ArrayList<Integer>();
                    temp.add(nums[first_index]);
                    temp.add(nums[second_index]);
                    temp.add(nums[zero.get(0)]);
                    threeSum.add(temp);
                    break;
                 }
           }



           j++;
           if(j > negative.size()-1){
             i++;
             j = i + 1;
           }

           if(i > negative.size()){
               break;
           }

           first_index = positive.get(i);
           second_index = negative.get(j);
        }

        return threeSum;
      }



   private List<List<Integer>> normalSearch(ArrayList<Integer> positive,ArrayList<Integer> negative, ArrayList<Integer> zero, int[] nums,
                                    List<List<Integer>> threeSum){
        int i = 0;
        int j = 0;
        int k = 0;

        int first_index = positive.get(0);
        int second_index = negative.get(0);
        int third_index = 0;

        while(true){
           int sum = nums[first_index] + nums[second_index];
           if(sum > 0){
              third_index = negative.get(0);
              for(int l = 0;l<negative.size();l++){
                 if(negative.get(l) == l){
                    continue;
                 }
                 if(sum + third_index == 0){
                    List<Integer> temp = new ArrayList<Integer>();
                    temp.add(nums[first_index]);
                    temp.add(nums[second_index]);
                    temp.add(nums[zero.get(0)]);
                    if(threeSum.contains(temp) == false){
                      threeSum.add(temp);
                    }
                    break;
                 }
              }
           } else if(sum < 0){
              third_index = positive.get(0);
              for(int l = 0;l<negative.size()-1;l++){
                 if(positive.get(l) == l){
                    continue;
                 }
                 if(sum + third_index == 0){
                    List<Integer> temp = new ArrayList<Integer>();
                    temp.add(nums[first_index]);
                    temp.add(nums[second_index]);
                    temp.add(nums[zero.get(0)]);
                    if(threeSum.contains(temp) == false){
                      threeSum.add(temp);
                    }
                    break;
                 }
              }
           } else if(sum == 0){
              if(zero.size() != 0){
                List<Integer> temp = new ArrayList<Integer>();
                temp.add(nums[first_index]);
                temp.add(nums[second_index]);
                temp.add(nums[zero.get(0)]);
                if(threeSum.contains(temp) == false){
                      threeSum.add(temp);
                }
              }
           }

           j++;
           if(j>negative.size()-1){
             i++;
             j = negative.get(0);
           }

           if(i > positive.size()-1){
             break;
           }

           first_index = positive.get(i);
           second_index = negative.get(j);
        }

        return threeSum;
      }


}