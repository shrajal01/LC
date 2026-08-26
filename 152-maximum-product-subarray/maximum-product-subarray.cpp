class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0];
        int mn = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            int oldMx = mx;
            int oldMn = mn;

            mx = max({x, x * oldMx, x * oldMn});
            mn = min({x, x * oldMx, x * oldMn});

            ans = max(ans, mx);
        }

    return ans;
    }
};