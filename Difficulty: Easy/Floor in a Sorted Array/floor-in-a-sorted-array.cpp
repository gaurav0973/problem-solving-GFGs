class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int start = 0, end = arr.size() - 1;
        int ans = -1;
        while(start <= end){
            int guess = (start+end)/2;
            if(arr[guess] <= x){
                ans = guess;
                start = guess + 1;
            }else{
                end = guess - 1;
            }
        }
        return ans;
    }
};
