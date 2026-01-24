class Solution {
  public:
    int josephus(int n, int k) {
        if(n == 1)
            return 1;
        
        // recursive result in 0-based index
        int res = (josephus(n - 1, k) + k - 1) % n;
        
        // convert to 1-based index
        return res + 1;
    }
};
