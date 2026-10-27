class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);

        if(abs(target) > sum || (sum + target) % 2 != 0)
            return 0;

        int s = (sum + target) / 2;
        vector<vector<int>> dp(n, vector<int>(s+1, 0));

        if(nums[0] == 0)
            dp[0][0]=2;
        else
            dp[0][0]=1;
        
        if (nums[0] != 0 && nums[0] <= s)
            dp[0][nums[0]] = 1;

        for(int i=1;i<n;i++){
            for(int j=0;j<=s;j++){
                int NP = dp[i-1][j];
                int P = 0;

                if(nums[i] <= j)
                    P = dp[i-1][j-nums[i]];
                
                dp[i][j] = P + NP;
            }
        }
        return dp[n-1][s];
    }
};