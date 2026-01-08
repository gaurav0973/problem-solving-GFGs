class Solution {
  public:
  
    int solve(vector<int>&vec , int tar){
        if(tar==-1) return 0 ;
        int n = vec.size();
        int l = 0 , r = 0 ;
        int sum = 0 ;
        int ans = 0 ;
        while(r<n){
            sum+=vec[r] ;
            while(sum>tar){
                sum-=vec[l] ;
                l++; 
            }
            if(sum<=tar) 
            ans += (r-l+1);
            r++; 
        }
        return ans;
    }
    
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size() ;
        for(int i=0;i<n;i++){
            if(arr[i]&1) arr[i]=1 ;
            else arr[i]=0 ;
        }
        
        return solve(arr,k)-solve(arr,k-1) ;
        
    }
};