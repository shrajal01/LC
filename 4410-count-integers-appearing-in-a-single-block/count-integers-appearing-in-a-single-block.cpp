class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i] != nums[i-1]) {
                if(mp[nums[i]] == 0) ans++;
                else if(mp[nums[i]] == 1) ans--;

                mp[nums[i]]++;
            }
        }

        return ans;
    }
};