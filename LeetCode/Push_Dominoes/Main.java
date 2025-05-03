import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String [] args) {
        Solution sol = new Solution();



    }
}


class Solution {
    public String pushDominoes(String dominoes) {
        Queue<Integer> q = new LinkedList<>();
        char[] dominoChars = dominoes.toCharArray();
        
        for(int i = 0; i < dominoes.length(); i++) {
            if(dominoes.charAt(i) == 'L' || dominoes.charAt(i) == 'R') {
                q.add(i);
            }
        }
        
        while(!q.isEmpty()) {
            char[] temp = dominoChars.clone(); 
            
            for(int i = 0; i < q.size(); i++) {
                int pos = q.poll();
                char c = dominoChars[pos];
                
                if(c == 'L') {
                    if(pos > 0 && temp[pos-1] == '.') {
                       
                        if(pos == 1 || dominoChars[pos-2] != 'R') {
                            temp[pos-1] = 'L';
                            q.add(pos-1);
                        }
                    }
                } 
                else if(c == 'R') {
                    if(pos < dominoes.length()-1 && temp[pos+1] == '.') {
                        if(pos == dominoes.length()-2 || dominoChars[pos+2] != 'L') {
                            temp[pos+1] = 'R';
                            q.add(pos+1);
                        }
                    }
                }
            }
            dominoChars = temp;
        }
        
        return new String(dominoChars);
    }
}