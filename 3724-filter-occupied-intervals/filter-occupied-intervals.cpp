class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(
        vector<vector<int>>& occupiedIntervals,
        int freeStart,
        int freeEnd
    ) {
        vector<vector<int>> ans;

        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        for (auto &interval : occupiedIntervals) {
            int start = interval[0];
            int end = interval[1];

            if (ans.empty() || start > ans.back()[1] + 1) {
                ans.push_back({start, end});
            } 
            else {
                ans.back()[1] = max(ans.back()[1], end);
            }
        }

        vector<vector<int>> result;

        for (auto &interval : ans) {
            int start = interval[0];
            int end = interval[1];

            if (end < freeStart) {
                result.push_back(interval);
            }
            else if (start > freeEnd) {
                result.push_back(interval);
            }
            else {
                if (start < freeStart) {
                    result.push_back({start, freeStart - 1});
                }

                if (end > freeEnd) {
                    result.push_back({freeEnd + 1, end});
                }
            }
        }

        return result;
    }
};