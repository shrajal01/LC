class Solution {
public:
    multiset<int> low, high;
    long long sumLow = 0, sumHigh = 0;
    
    void add (int val){
        if(low.empty() || val<= *low.rbegin()){
            low.insert(val);
            sumLow += val;
        }
        else{
            high.insert(val);
            sumHigh += val;
        }

        balance();
    }

    void remove(int val){
        auto it = low.find(val);

        if(it != low.end()){
            sumLow -= val;
            low.erase(it);
        }
        else{
            it = high.find(val);
            sumHigh -= val;
            high.erase(it);
        }
        balance();
    }
    void balance(){
        int x = (low.size() + high.size() + 1) / 2;

        while(low.size() > x){
            auto it = prev(low.end());
            int val = *it;

            low.erase(it);
            sumLow -= val;

            high.insert(val);
            sumHigh += val;
        }
        while(low.size() < x){
            auto it = high.begin();
            int val = *it;

            high.erase(it);
            sumHigh -= val;

            low.insert(val);
            sumLow += val;
        }
    }
    long long getCost(){
        long long median = *low.rbegin();
        
        return median * low.size() - sumLow + sumHigh -median * high.size();
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n-x+1);
        for(int i = 0; i < x; i++){
            add(nums[i]);
        }

        cost[0] = getCost();

        for(int i = x; i < n; i++){
            remove(nums[i-x]);
            add(nums[i]);

            cost[i-x+1] = getCost();
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(n+1, vector<long long>(k+1,INF));

        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                dp[i][j] = dp[i-1][j];

                if(i >= x && dp[i-x][j-1] != INF){
                    dp[i][j] = min(dp[i][j], dp[i-x][j-1] + cost[i-x]);
                }
            }
        }
        return dp[n][k];
    }
};