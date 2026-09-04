class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()){
            return "";
        }
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for (char ch : t) {
            need[ch]++;
        }

        int l = 0;
        int r = 0;

        int formed = 0;
        int required = need.size();

        int minLen = INT_MAX;
        int start = 0;

        while (r < s.size()) {
            char ch = s[r];
            window[ch]++;

            if (need.count(ch) && window[ch] == need[ch]) {
                formed++;
            }

            while (formed == required) {

                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                char leftChar = s[l];
                window[leftChar]--;

                if (need.count(leftChar) &&
                    window[leftChar] < need[leftChar]) {
                    formed--;
                }

                l++;
            }

            r++;
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};