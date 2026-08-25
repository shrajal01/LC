class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        for (int i = 1; ; i++) {
            int x = i * k;

            if (find(nums.begin(), nums.end(), x) == nums.end())
                return x;
        }
    }
};