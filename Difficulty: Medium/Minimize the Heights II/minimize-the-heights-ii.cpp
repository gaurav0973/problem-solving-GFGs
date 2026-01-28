class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int largest = arr[n-1];
        int smallest = arr[0];
        int ans = largest - smallest;
        for(int i=1; i<n; i++){
            largest = max(arr[n-1]-k, arr[i-1] + k);
            smallest = min(arr[0]+k, arr[i] -k);
            if(smallest < 0)
                continue;
            if(largest < 0)
                continue;
            ans = min(ans, largest - smallest);
        }
        return ans;
        
    }
};