class Solution {
  public:
    void rotate(vector<int> &arr){
        int x = arr[arr.size()-1];
        arr.pop_back();
        arr.insert(begin(arr), x);
    }
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int ans = 0;
        int totalSum = 0;
        int currSum = 0;
        for(int i=0; i<n; i++){
            totalSum += arr[i];
            currSum += i*arr[i];
        }
        ans = currSum;
        for(int i=0; i<n; i++){
            currSum = currSum + totalSum - n*arr[n-i-1];
            ans = max(currSum, ans);
        }
        return ans;
        
    }
};