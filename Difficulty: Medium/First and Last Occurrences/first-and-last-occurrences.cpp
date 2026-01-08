class Solution {
  public:
    int first(vector<int> &arr, int x){
         int start = 0, end = arr.size() - 1;
        int ans = -1;
        while(start <= end){
            int guess = (start+end)/2;
            if(arr[guess] < x){
                start = guess + 1;
            }else if(arr[guess] > x){
                end = guess - 1;
            }else{
                ans = guess;
                end = guess-1;
            }
        }
        return ans;
    }
    int last(vector<int> &arr, int x){
         int start = 0, end = arr.size() - 1;
        int ans = -1;
        while(start <= end){
            int guess = (start+end)/2;
            if(arr[guess] < x){
                start = guess + 1;
            }else if(arr[guess] > x){
                end = guess - 1;
            }else{
                ans = guess;
                start = guess+1;
            }
        }
        return ans;
    }
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int a = first(arr, x);
        if(a == -1){
            return {-1,-1};
        }
        return {a, last(arr, x)};
        
    }
};