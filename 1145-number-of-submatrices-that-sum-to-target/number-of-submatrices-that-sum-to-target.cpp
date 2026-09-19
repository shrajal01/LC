class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;

        for (int top = 0; top < m; top++) {

            vector<int> colSum(n, 0);

            for (int bottom = top; bottom < m; bottom++) {

                // Add current row into column sums
                for (int col = 0; col < n; col++) {
                    colSum[col] += matrix[bottom][col];
                }

                // Now find subarrays with sum = target
                unordered_map<int, int> mp;

                mp[0] = 1;

                int prefixSum = 0;

                for (int col = 0; col < n; col++) {

                    prefixSum += colSum[col];

                    int needed = prefixSum - target;

                    if (mp.count(needed)) {
                        ans += mp[needed];
                    }

                    mp[prefixSum]++;
                }
            }
        }

        return ans;
    }
};