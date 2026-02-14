class Solution {
  public:
    bool isPossibleAns(vector<int> &arr, int mid, int k)
    {
        int cnt = 1;
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            if(sum > mid){
                cnt++;
                sum = arr[i];
            }
            
        }
        return cnt <= k;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int start = *max_element(arr.begin(), arr.end());  // must be max
        int end = 0;
        for(auto &v : arr) end+=v;
        
        int ans = -1;
        while(start <= end)
        {
            int mid = (start + end)/2;
            if(isPossibleAns(arr, mid, k)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
        
    }
};