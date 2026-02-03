class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        int ans  = 0;
        int minL = prices[0];
        for(int i=1; i<n; i++){
            int buy = minL;
            int sell = prices[i];
            ans = max(ans, sell - buy);
            minL = min(minL, prices[i]);
        }
        return ans;
    }
};
