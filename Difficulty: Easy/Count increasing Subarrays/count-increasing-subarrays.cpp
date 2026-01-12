class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int l = 0, r = 1;
        int n = arr.size();
        if(n <=1)
            return 0;
        int cnt = 0;
        while(r < n){
            
            // invalid
            if(arr[r] <= arr[r-1])
                l = r;
            
            // valid
            cnt += (r-l);
            r++;
        }
        return cnt;
    }
};
