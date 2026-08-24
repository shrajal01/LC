class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);

        int ans = sum;

        for (int i = n - 1; i >= 2; i--) {
            sum -= stones[i];
            ans = max(ans, sum - ans);
        }

        return ans;
    }
};