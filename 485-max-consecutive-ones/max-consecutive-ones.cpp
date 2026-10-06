class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0, mc=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                c+=1;
            }
            else{
                c=0;
            }
            mc=max(mc,c);
        }
        return mc;
    }
};