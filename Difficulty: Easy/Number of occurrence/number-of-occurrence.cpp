class Solution {
  public:
    int first(vector<int> &nums, int x){
        int start = 0, end = nums.size()-1;
        int ans = -1;
        while(start <= end){
            int guess = (start+end)/2;
            if(nums[guess] < x){
                start = guess + 1;
            }
            else if(nums[guess] > x){
                end = guess - 1;
            }else{
                ans = guess;
                end = guess-1;
            }
        }
        return ans;
    }
    int last(vector<int> &nums, int x){
        int start = 0, end = nums.size()-1;
        int ans = -1;
        while(start <= end){
            int guess = (start+end)/2;
            if(nums[guess] < x){
                start = guess + 1;
            }
            else if(nums[guess] > x){
                end = guess - 1;
            }else{
                ans = guess;
                start = guess + 1;
            }
        }
        return ans;
    }
    int countFreq(vector<int>& arr, int target) {
        int x = first(arr, target);
        if(x == -1) 
            return 0;
        int y = last(arr, target);
        return y-x+1;
        
    }
};
