class Solution {
  public:
    bool canMake(int time, vector<int>& ranks, int n) {
        int donuts = 0;
        
        for (int r : ranks) {
            int k = 0;
            int currTime = 0;
            
            // Count how many donuts this chef can make
            while (true) {
                currTime += r * (k + 1);
                if (currTime > time) break;
                k++;
            }
            
            donuts += k;
            if (donuts >= n) return true;
        }
        return false;
    }

    int minTime(vector<int>& ranks, int n) {
        int low = 0;
        int high = *min_element(ranks.begin(), ranks.end()) * n * (n + 1) / 2;
        int ans = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canMake(mid, ranks, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
