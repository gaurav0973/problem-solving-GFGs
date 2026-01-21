// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& nums) {
        // Code here
        int prevBest = nums[0];
        int ans = nums[0];
        for(int i=1; i<nums.size(); i++){
            int x = prevBest + nums[i];
            int y = nums[i];
            prevBest = min(x,y);
            ans = min(ans, prevBest);
        }
        return ans;
    }
};
