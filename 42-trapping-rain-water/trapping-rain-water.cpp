class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>l(n),r(n);

        l[0]=height[0];
        for(int i=1;i<n;i++){
            l[i]=max(l[i-1],height[i]);
        }

        r[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            r[i]=max(r[i+1],height[i]);
        }
        long long water =0;

        for(int i=0;i<n;i++){
            water+=min(l[i],r[i])-height[i];
        }
        return water;
    }
};