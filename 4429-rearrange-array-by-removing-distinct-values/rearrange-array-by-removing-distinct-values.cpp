class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int x : nums)
            mp[x]++;

        vector<int> keys;

        for(auto &p : mp)
            keys.push_back(p.first);

        sort(keys.begin(), keys.end());

        vector<int> ans;

        while(!keys.empty()) {
            vector<int> next;

            for(int x : keys) {
                ans.push_back(x);
                mp[x]--;

                if(mp[x] > 0)
                    next.push_back(x);
            }

            keys = next;
        }

        return ans;
    }
};