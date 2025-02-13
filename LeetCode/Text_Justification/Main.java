import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String [] args) {
        String[] words = {"This", "is", "an", "example", "of", "text", "justification."};
//        String[] words = {"What","must","be","acknowledgment","shall","be"};
//        String[] words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
        int maxWidth = 16;

        Solution solution = new Solution();

        List<String> justified = solution.fullJustify(words,maxWidth);

        for(int i = 0;i<justified.size();i++){
            System.out.println(justified.get(i) + " " + justified.get(i).length());
        }
   
    }

}

class Solution {
    /* 
    Given an array of strings words and a width maxWidth, format the text such that each 
    line has exactly maxWidth characters and is fully (left and right) justified.
    You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
    Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
    Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, 
    the empty slots on the left will be assigned more spaces than the slots on the right.
    For the last line of text, it should be left-justified, and no extra space is inserted between words.
    */
    public List<String> fullJustify(String[] words, int maxWidth) {
        ArrayList<String> justified = new ArrayList<String>(); 
        int totalLength = 0;
        int runningLength = 0;
        String grouper = "";

        //SORT WORDS INTO GROUPS
        for(int i = 0; i < words.length;i++){
            runningLength += words[i].length() + 1; // +1 for space
//System.out.println(words[i] + " : " + words[i].length());
//System.out.println("Running Length is "  + runningLength);

            if(runningLength-2 >= maxWidth){ //Ignore current word,group together then check again - 2 for extra spaces from current word and past word
                grouper = grouper.trim();
                totalLength += grouper.length(); 
                justified.add(grouper);
                i--;
                runningLength = 0;
                grouper = "";
            } else {
                grouper += words[i] + " ";
           }
        }

        if(grouper != ""){
            grouper.trim();
            StringBuilder sb = new StringBuilder(grouper);
            for (int j = 0; j < maxWidth - grouper.length(); j++) {
                sb.append(" ");
            }
            grouper = sb.toString();
            justified.add(grouper);
            totalLength += grouper.length();
        }

System.out.println("Max Width:" + maxWidth);
System.out.println("Length: " + totalLength);
        int lines = totalLength/maxWidth;
        if(totalLength%maxWidth > 0){
            lines++;
        }
System.out.println("Lines req: " + totalLength + "/" + maxWidth + " = " + lines);

        //ADD SPACES
        for(int i = 0; i < justified.size();i++){
            if(justified.get(i).length() == maxWidth){
                continue;
            } 
            int spaces = justified.get(i).length() - justified.get(i).replace(" ", "").length();
            int reqSpaces = maxWidth - justified.get(i).length() - spaces;
System.out.println("SPACES : " + spaces);
System.out.println("Required Spaces Count :" + reqSpaces);
            Scanner scanner = new Scanner(justified.get(i));
            //FORMAT
            while(justified.get(i).length() <= maxWidth){
                String word = scanner.next();  // Gets "Hello"
                    for(int k = 0;k < spaces;k++){


                    }
                justified.set(i,word);
            }

            scanner.close();
        }


        return justified;
        
    }
}