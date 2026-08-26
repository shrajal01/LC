class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> p;

        for(int i=0;i<s.size();i++)
            if(s[i]=='1') p.push_back(i);

        string ans="";

        for(int i=0;i+k<=p.size();i++){
            int l=p[i], r=p[i+k-1];

            string t=s.substr(l,r-l+1);

            if(ans=="" || t.size()<ans.size() ||
               (t.size()==ans.size() && t<ans))
                ans=t;
        }

        return ans;
    }
};