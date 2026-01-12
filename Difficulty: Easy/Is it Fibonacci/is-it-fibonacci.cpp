class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // If N is within the given initial array
        if (N <= K) {
            return GeekNum[N - 1];
        }
        
        long long windowSum = 0;
        
        // Initial sum of first K elements
        for (int i = 0; i < K; i++) {
            windowSum += GeekNum[i];
        }
        
        // Generate terms from K+1 to N
        for (int i = K; i < N; i++) {
            long long next = windowSum;
            windowSum = windowSum - GeekNum[i - K] + next;
            GeekNum.push_back(next);
        }
        
        return GeekNum[N - 1];
    }
};
