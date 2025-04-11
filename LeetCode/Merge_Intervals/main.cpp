#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include <vector>


using namespace std::vector;

    
int main(int argc,char *args[]){

}
class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
            //vector<vector<int>> vec2(intervals.size(), vector<int>(2));
            vector<vector<int>> merged;
            bool lastMerged = false;
            vector<int> stored;
    
            sort(intervals.begin(), intervals.end(), [](auto const& lhs,  auto const& rhs) {
                return lhs[0] < rhs[0];
            });
    
            for(int i = 0; i < intervals.size()-1;i++){
    
    cout << "i is " << i << endl;
    
                if(stored.size() != 0){
                    vector<int> temp;
                    temp = mergehelper(stored,intervals[i]);
                    if(temp.size() == 0){
                        merged.push_back(stored);
                        stored.clear();
                        i--;
                    } else {
                        stored = temp;
                    }
    
                } else {
                    stored = mergehelper(intervals[i],intervals[i+1]);
                    if(stored.size() != 0){
                        i++;
                    } else{
                        merged.push_back(intervals[i]);
                    }
                }
            }
    
            if(stored.size() != 0){
                vector<int> temp;
                temp = mergehelper(stored,intervals[intervals.size()-1]);
                if(temp.size() == 0){
                    merged.push_back(stored);
                    merged.push_back(intervals[intervals.size()-1]);
                    stored.clear();
                } else {
                    merged.push_back(temp);
                }
            } else {
                merged.push_back(intervals[intervals.size()-1]);
            }
    
    
    
            return merged;
        
            
        }
    
        vector<int> mergehelper(vector<int> &vec1, vector<int> &vec2){
            vector<int> stored;
    cout << "comparing " << vec1[0] << " " << vec1[1] 
    << " and " << vec2[0] << " " << vec2[1] << endl;
    
            if(vec1[0] == vec2[0]){
                    int leftbound = vec1[0];
                    int rightbound = vec1[1] > vec2[1] ? vec1[1]:vec2[1]; 
                    stored.push_back(leftbound);
                    stored.push_back(rightbound);
                } else if(vec1[1] >= vec2[0] || vec1[1] == vec2[1]) {
                    int leftbound = vec1[0];
                    int rightbound = vec1[1] > vec2[1] ? vec1[1]:vec2[1]; 
                    stored.push_back(leftbound);
                    stored.push_back(rightbound);
            }
    
            return stored;
    
        }
    };