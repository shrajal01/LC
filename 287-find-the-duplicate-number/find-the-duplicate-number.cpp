class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>f;
        for(int x:nums)
            f[x]++;

        for(int x:nums){
            if(f[x] > 1) return x;
        }
        return -1; 
    }
};