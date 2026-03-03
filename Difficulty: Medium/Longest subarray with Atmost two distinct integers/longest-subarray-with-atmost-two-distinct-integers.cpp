
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        int l = 0;
        int r = 0;
        unordered_map<int,int> mpp;
        int maxLen = 0;
        while(r < n)
        {
            mpp[arr[r]]++;
            while(mpp.size() > 2){
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0)
                    mpp.erase(arr[l]);
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};

