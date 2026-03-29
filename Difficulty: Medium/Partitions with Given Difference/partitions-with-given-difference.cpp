class Solution {
  public:
    int solve(int idx , vector<int>& arr , int tar , vector<vector<int>>&dp){
        
        if(idx == 0){
            if(tar == 0 && arr[0] == tar)
                return 2;
            if(tar == 0 || arr[0] == tar)
                return 1;
            return 0;
        }
        
        if(dp[idx][tar] != -1) return dp[idx][tar];
        
        int take = 0 , notTake = 0 ;
        if(arr[idx] <= tar) take =solve(idx - 1 , arr , tar - arr[idx] ,dp) ;
        notTake = solve(idx - 1, arr , tar ,dp) ;
        
        return dp[idx][tar] = take + notTake ;
        
    }
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int sum = 0;
        for(auto &s : arr) sum+=s;
        
        if ((sum + d) % 2 != 0 || (sum + d) < 0) return 0;
        int target = (sum + d) / 2;
        vector<vector<int>> dp(arr.size() + 1 , vector<int>(target + 1 , -1)) ;
        return solve(n-1, arr , target , dp) ;
        
    }
};