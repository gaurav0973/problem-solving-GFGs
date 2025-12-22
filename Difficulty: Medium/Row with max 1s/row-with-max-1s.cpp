class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        if (n == 0) return -1;
        int m = arr[0].size();
        
        int maxCount = 0;
        int maxRow = -1;
        
        for (int i = 0; i < n; i++) {
            // Use binary search to find first occurrence of 1
            int low = 0, high = m - 1;
            int firstOne = m;  // Initialize to m (no 1s found)
            
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[i][mid] == 1) {
                    firstOne = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            
            // Number of 1s in this row = m - firstOne
            int countOnes = m - firstOne;
            
            if (countOnes > maxCount) {
                maxCount = countOnes;
                maxRow = i;
            }
        }
        
        return maxRow;
    }
};