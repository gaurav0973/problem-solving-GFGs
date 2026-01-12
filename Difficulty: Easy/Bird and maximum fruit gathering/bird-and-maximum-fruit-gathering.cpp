class Solution {
  public:
    int maxFruits(vector<int>& arr, int totalTime) {
        // code here
        int l =0, r = 0;
        int n = arr.size();
        long long timeMax = 2*totalTime;
        int sum = 0;
        int ans = 0;
        while(r < n){
            sum += arr[r];
            
            while(l <= r && (2*(r-l+1) -1) > timeMax){
                sum-=arr[l];
                l++;
            }
            
            ans = max(ans, sum);
            r++;
        }
        return ans;
        
    }
};
