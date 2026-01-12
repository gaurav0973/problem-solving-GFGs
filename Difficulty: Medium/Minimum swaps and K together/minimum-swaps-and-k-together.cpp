class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        int n = arr.size();

        // Step 1: count elements <= k
        int good = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= k)
                good++;
        }

        // If nothing or only one good element
        if (good <= 1)
            return 0;

        // Step 2: unt bad elements in first window
        int badCount = 0;
        for (int i = 0; i < good; i++) {
            if (arr[i] > k)
                badCount++;
        }

        int ans = badCount;

        // Step 3: slide the window
        int l = 0, r = good;
        while (r < n) {

            // include r
            if (arr[r] > k)
                badCount++;

            // exclude l
            if (arr[l] > k)
                badCount--;

            ans = min(ans, badCount);
            l++;
            r++;
        }

        return ans;
    }
};
