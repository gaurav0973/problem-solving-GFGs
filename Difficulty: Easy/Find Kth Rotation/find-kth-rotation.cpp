class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int start = 0, end = n-1;
        int ans = 0;
        while(start <= end){
            int guess = (start + end)/2;
            if(arr[guess]> arr[n-1]){
                start = guess+1;
            }else{
                ans = guess;
                end = guess-1;
            }
        }
        return ans;
    }
};
