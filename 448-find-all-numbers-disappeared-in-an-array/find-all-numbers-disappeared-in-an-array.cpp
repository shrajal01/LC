class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n + 1, 1);

        for (int x : nums)
            if (x <= n)
                a[x] = 0;

        vector<int> ans;

        for (int i = 1; i <= n; i++)
            if (a[i])
                ans.push_back(i);

        return ans;
    }
};