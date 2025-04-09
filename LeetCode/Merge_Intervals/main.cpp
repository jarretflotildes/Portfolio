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
    
            sort(intervals.begin(), intervals.end(), [](auto const& lhs,  auto const& rhs) {
                return lhs[0] < rhs[0];
            });
    
            for(int i = 0; i < intervals.size()-1;i++){
    
                if(intervals[i][1] >= intervals[i+1][0] ||
                    intervals[i][1] >= intervals[i+1][1]
                ){
                    //Merge
                    vector<int> temp;
                    int left = intervals[i][0] <= intervals[i+1][0] ? intervals[i][0]:intervals[i][1];
                    int right = intervals[i][1] >= intervals[i+1][1] ? intervals[i][1]:intervals[i+1][1];
                    temp.push_back(left);
                    temp.push_back(right);
                    merged.push_back(temp);
                    i++;
                    lastMerged = true;
                } else {
                    merged.push_back(intervals[i]);
                    lastMerged = false;
                }
            }
    
            if(lastMerged == false){
                merged.push_back(intervals[intervals.size()-1]);
            }
    
            return merged;
        
        }
    
    };
}
 