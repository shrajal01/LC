class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> ans(m, -1);
        stack<int> st;
        unordered_map<int,int> mp;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && st.top() <= nums2[i])
                st.pop();

            mp[nums2[i]] = st.empty() ? -1 : st.top();

            st.push(nums2[i]);
        }

        for(int i = 0; i < m; i++) {
            ans[i] = mp[nums1[i]];
        }

        return ans;
    }
};