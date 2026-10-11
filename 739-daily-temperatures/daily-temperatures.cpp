class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int>ans(n);
        stack<int>st;
        for (int i = 0; i < n; i++) {
        while (!st.empty() && temp[i] > temp[st.top()]) {
            int j = st.top();
            st.pop();

            ans[j] = i - j;
        }

        st.push(i);
    }
    return ans;
    }
};