class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int mx = *max_element(nums.begin(),nums.end());
        for(auto x : nums){
            ans+=mx-x;
        }
        return ans;
    }
};