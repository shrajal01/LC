class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int t=nums.size()/3;
        unordered_map<int,int>f;
        vector<int>res;

        for(int i : nums){
            f[i]++;
            if(f[i] == t+1)  res.push_back(i);
        }
        return res;
    }
};