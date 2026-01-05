// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int start = 0;
        int end = arr.size() - 1;
        int ans = -1;
        while(start <= end){
            int guess = (start+end)/2;
            if(arr[guess] < x){
                start = guess + 1;
            }else{
                ans = guess;
                end = guess-1;
            }
        }
        return ans;
    }
};