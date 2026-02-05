class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int l = 0;
        int r = 0;
        int cnt = 0;
        int n = arr.size();
        int maxLen = 0;
        
        while(r < n)
        {
            if(arr[r] == 0)
                cnt++;
            
            while(cnt > k){
                if(arr[l] == 0)
                    cnt--;
                l++;
            }
            
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};
