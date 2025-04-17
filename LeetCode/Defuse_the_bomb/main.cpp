class Solution {
    public:
        vector<int> decrypt(vector<int>& code, int k) {
    
            if(k >= 0){
                return pos(code,k);
            } 
    
            return neg(code,k);
    
    
        }
    
        vector<int> pos(vector<int> &code, int k){
            vector<int> decrypted;
    
            for(int i = 0;i < code.size();i++){
                int counting = k;
                int j = i+1;
                int sum = 0;
    
                while(counting > 0){
                    if(j > code.size()-1){
                        j = 0;
                    }
                    sum += code[j];
                    j++;
                    counting--;
                }
                decrypted.push_back(sum);
    
            }
    
            return decrypted;
    
        }
    
        vector<int> neg(vector<int> &code, int k){
            vector<int> decrypted;
    
            for(int i = 0;i < code.size();i++){
                int counting = k;
                int j = i-1;
                int sum = 0;
    
                while(counting != 0){
                    if(j < 0){
                        j = code.size() - 1;
                    }
                    sum += code[j];
                    j--;
                    counting++;
                }
                decrypted.push_back(sum);
            }
    
            return decrypted;
    
    
        }
    
    
    };