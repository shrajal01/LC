class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    vector<int> last_seen(256, -1);
    
    int ans = 0;
    int left = 0;

    for (int i=0; i<s.length();i++) {
        char current_char = s[i];
        if (last_seen[current_char] >= left) {
            left = last_seen[current_char] + 1;
        }
        last_seen[current_char] = i;
        ans=max(i-left+1,ans);
    }
    return ans;
    }
};