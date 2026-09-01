class Solution {
public:
    bool isPalindrome(const string &s, int l, int r){
        while(l<r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r){
            if(tolower(s[l])!=tolower(s[r])){
                return isPalindrome(s,l+1,r) || isPalindrome(s,l,r-1);
            }
            l++;
            r--;
        }
        return true;
    }
};