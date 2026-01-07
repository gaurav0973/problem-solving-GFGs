

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mpp;
        int l=0, r = 0;
        vector<int> ans;
        
        //create a constant window
        while(r < k-1){
            mpp[arr[r]]++;
            r++;
        }
        while(r < n)
        {
            if(r-l+1 > k){
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0)
                    mpp.erase(arr[l]);
                l++;
            }
            mpp[arr[r]]++;
            ans.push_back(mpp.size());
            r++;
        }
        return ans;
    }
};

