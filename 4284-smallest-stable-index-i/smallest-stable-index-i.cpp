class Solution {
public:
    int mx(vector<int>&nums,int s,int e){
        int mxs=nums[s];
        for(int i=s;i<=e;i++){
            if(nums[i]>mxs) mxs=nums[i];
        }
        return mxs;
    }
    int mn(vector<int>&nums,int s,int e){
        int mns=nums[s];
        for(int i=s;i<=e;i++){
            if(nums[i]<mns) mns=nums[i];
        }
        return mns;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int s = mx(nums,0,i)-mn(nums,i,n-1);
            if(s <= k) return i;
        }
        return -1;
    }
};