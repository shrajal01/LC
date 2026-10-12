class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        const long long MOD = 1e9+7;
        vector<int>l(n),r(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            l[i]=st.empty()? i+1 : i-st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            r[i]=st.empty() ? n-i : st.top()-i;
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long contrib=(long long)arr[i]*l[i]*r[i];
            ans=(ans+contrib)%MOD;
        }
        return ans;
    }
};