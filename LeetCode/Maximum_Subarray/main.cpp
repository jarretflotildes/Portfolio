class Solution {
    public:
    
        struct Node{
            int length;
            int sum;
            bool target;
        };
    
    
        int minSubArrayLen(int target, vector<int>& nums) {
            int length = nums.size();
            vector<Node> nodes;
    
            int runningSum = 0;
            int runningLength = 0;
            int startNode = 0;
    
            for(int i = 0;i < nums.size();i++){
                Node section;
                section.sum = nums[i];
                section.length = 1;
                section.target = false;
    
                for(int j = startNode; j < nodes.size();j++){
                    nodes[j].sum += nums[i];
                    nodes[j].length++;
                    if(nodes[j].sum >= target){
                        nodes[j].target = true;
                        startNode++;
                    }
                }
    
                nodes.push_back(section);
    
                if(i == 0){
                    if(nodes[i].sum >= target){
                        nodes[i].target = true;
                        startNode++;
                    }
                }
    
            }
    
            if(nodes[nodes.size()-1].sum >= target){
                nodes[nodes.size()-1].target = true;
            }
    
            length = 0;
            int lowest = nodes[0].length;
    
            for(int i = 0;i < nodes.size();i++){
    //cout << nodes[i].sum << " in " << nodes[i].length << endl;
                if(nodes[i].length <= lowest && nodes[i].target == true){
                    length = nodes[i].length;
                    lowest = length;
    // cout << "Lowest is now " << lowest << endl;               
                    
                }       
            }
    
            return length;
            
        }
    };