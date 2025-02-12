import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String [] args) {
        String[] words = {"This", "is", "an", "example", "of", "text", "justification."};
        int maxWidth = 16;

        Solution solution = new Solution();

        List<String> justified = solution.fullJustify(words,maxWidth);
        System.out.println(justified);
   
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

        for(int i = 0; i < words.length;i++){
            runningLength += words[i].length();
            totalLength += words[i].length();
System.out.println(words[i] + " : " + words[i].length());
            if(runningLength >= maxWidth){
                grouper = grouper.replaceFirst("^\\s+","");
                justified.add(grouper);
                i--;
                totalLength -= words[i].length();
                runningLength = 0;
                grouper = "";
            } else {
                grouper += " " + words[i];
            }
        }

        if(grouper != ""){
            grouper.replaceFirst("^\\s+","");
            justified.add(grouper);
            grouper = "";
        }



System.out.println();
System.out.println("Max Width:" + maxWidth);
System.out.println("Length: " + totalLength);
        int lines = totalLength/maxWidth;
        if(totalLength%maxWidth > 0){
            lines++;
        }
System.out.println("Lines req: " + lines);

        return justified;
        
    }
}