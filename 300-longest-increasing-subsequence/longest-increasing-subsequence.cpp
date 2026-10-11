class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n= a.size();
        vector<int>dp(n,1);
        int best=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]+1);
            }
            best=max(best,dp[i]);
        }
        return best;
    }
};