class Solution {
  public:
    virtual int count(vector<int> &arr, int m){
      int c=0;
      for(int &x: arr){
        c += (x/m);
        if(x%m != 0) c++;
      }
      return c;
    }
    
    virtual void bs(int s, int e, vector<int> &arr, int &k, int &ans){
      if(s>e) return;
      int m=s+(e-s)/2;
      
      if(count(arr, m) <= k){
         ans = m;
         bs(s, m-1, arr, k, ans);
         return;
      }
      
      bs(m+1, e, arr, k, ans);
      return;
      
    }
    virtual int kokoEat(vector<int>& arr, int k){
      int ans=INT_MAX;
      int s=1;
      int e=*max_element(arr.begin(), arr.end());
    //   for(int &x: arr) e+=x;
      
      bs(s, e, arr, k, ans);
      return ans;
    }
    
    virtual ~Solution(){}
};

