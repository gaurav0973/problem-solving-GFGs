class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(),arr.end()) ;
        sort(dep.begin() , dep.end()) ;
        int n = arr.size() ;
        
        int i=0, j = 0;
        int cnt = 0;
        int ans = 0;
        while(i<n && j <n){
            if(arr[i] <= dep[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
