class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());

        int len=0;
        for(int x:s){
            if(!s.count(x-1)){
                int y=x;

                while(s.count(y))
                    y++;
                len = max(len,y-x);  
            }    
        }
        return len;
    }
};