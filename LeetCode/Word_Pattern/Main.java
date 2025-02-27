import java.util.HashMap; // import the HashMap class



public class Main {

    public static void main(String [] args) {
        Solution solution = new Solution();

        String pattern = "aabb";
        String words = "cat cat cat cat";

        System.out.println("Is " + words.toString() + " a pattern?");
        System.out.println(solution.wordPattern((pattern), words));
  
    }

}

class Solution {

    
    public boolean wordPattern(String pattern, String s) {
        HashMap<String,String> conversion  = new HashMap<String, String>();
 System.out.println("Pattern is " + pattern);
      
        if(s.replaceAll("[^ ]", "").length() > pattern.length()-1){
           return false;
        }
         
        if(s.replaceAll("[^ ]", "").length() < pattern.length() - 1){
           return false;
        }
 
        int i = 0;
        for(String word: s.split(" ")){
           System.out.println(word);
           String Letter = String.valueOf(pattern.charAt(i));
           i++;  
 
           if(conversion.get(Letter) != null){
 System.out.println("Comparing " + word + " and " + conversion.get(Letter));
             if(word.equals(conversion.get(Letter)) == false){
 
                 return false;
             }
           } else if (conversion.containsValue(word)) {
             return false;
           } else {
             conversion.put(Letter,word);
           }
        }
 
         return true;
     }

}