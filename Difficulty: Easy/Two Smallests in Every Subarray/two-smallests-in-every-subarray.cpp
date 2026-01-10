class Solution {
  public:
    int maxSum(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return -1;

        int ans = INT_MIN;

        int l = 0;
        for (int r = 1; r < n; r++) {
            ans = max(ans, arr[l] + arr[r]);
            l++;
        }

        return ans;
    }
};
