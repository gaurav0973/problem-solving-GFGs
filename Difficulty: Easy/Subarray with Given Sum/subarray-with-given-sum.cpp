// User function Template for C++
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>& arr, int sum) {
        int l = 0;
        int r = 0;
        int n = arr.size();
        int currSum = 0;
        while(r < n){
            currSum += arr[r];
            
            while(l  <= r &&  currSum > sum){
                currSum-=arr[l];
                l++;
            }
            
            if(l <= r && currSum == sum)
                return {l+1,r+1};
            
            r++;
        }
        return {};
    }
};