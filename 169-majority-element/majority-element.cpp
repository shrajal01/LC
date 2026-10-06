class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int t=nums.size()/2;
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
            if(mp[i]>t)
                return i;
        }
        return -1;
    }
};