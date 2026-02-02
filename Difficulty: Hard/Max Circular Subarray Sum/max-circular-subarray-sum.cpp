class Solution {
public:
    int findMaxSum(vector<int> &arr) {
        int n = arr.size();
        int bestEnding = arr[0];
        int ans = arr[0];
        for(int i = 1; i < n; i++) {
            bestEnding = max(bestEnding + arr[i], arr[i]);
            ans = max(bestEnding, ans);
        }   
        return ans;
    }
    
    int findMinSum(vector<int> &arr) {
        int n = arr.size();
        int bestEnding = arr[0];
        int ans = arr[0];
        for(int i = 1; i < n; i++) {
            bestEnding = min(bestEnding + arr[i], arr[i]);
            ans = min(bestEnding, ans);
        }   
        return ans;
    }
    
    int findTotalSum(vector<int> &arr) {
        int total = 0;
        for(int num : arr) {
            total += num;
        }   
        return total;
    }
    
    int maxCircularSum(vector<int> &arr) {
        int maxSum = findMaxSum(arr);
        
        // all numbers are negative
        if (maxSum < 0)
            return maxSum;
        int totalSum = findTotalSum(arr);
        int minSum = findMinSum(arr);
        
        
        return max(maxSum, totalSum - minSum);
    }
};