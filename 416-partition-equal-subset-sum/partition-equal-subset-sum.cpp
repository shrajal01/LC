class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(), 0);

        if(sum % 2) return false;

        int target = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(target+1,false));

        for(int i=0;i<n;i++)
            dp[i][0] = true;

        if(nums[0] <= target)
            dp[0][nums[0]] = true;

        for(int i = 1; i<n; i++){
            for(int j = 1; j<=target;j++){
                bool NP=dp[i-1][j];
                bool P=false;

                if(nums[i] <= j)
                    P = dp[i-1][j-nums[i]];

                dp[i][j] = P || NP;
            }
        }
        return dp[n-1][target];
    }
};