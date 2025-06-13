class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy=prices[0];
        int ans, profit=0;
        for (int i =0; i<n; i++ ){
            if(buy>prices[i]){
                buy = prices[i];
            }
                ans = prices[i]-buy;
                profit = max(profit, ans);
        }
        return profit;
    }
};