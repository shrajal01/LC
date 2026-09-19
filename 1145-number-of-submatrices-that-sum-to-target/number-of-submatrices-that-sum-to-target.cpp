class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                prefix[i][j] = matrix[i - 1][j - 1]
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];
            }
        }

        int count = 0;
        for (int top = 0; top < m; top++) {
            for (int bottom = top; bottom < m; bottom++) {

                for (int left = 0; left < n; left++) {
                    for (int right = left; right < n; right++) {

                        int sum = prefix[bottom + 1][right + 1]
                                - prefix[top][right + 1]
                                - prefix[bottom + 1][left]
                                + prefix[top][left];

                        if (sum == target)
                            count++;
                    }
                }
            }
        }

        return count;
    }
};