
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        
        int n = arr.size();
        int cnt = 0;
        int x = 0;
        unordered_map<int, int> mpp;
        mpp[x]++;
        
        for(int i=0; i<n; i++){
            
            x = x^arr[i];
            int y = x^k;
            cnt += mpp[y];
            mpp[x]++;
            
        }
        return cnt;
        
    }
};

