
// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        auto lambda = [](int &a, int &b){
            return a>b;
        };
        sort(nums.begin(), nums.end(), lambda);
        for(int i=0; i<n; i++){
            int H = i+1;
            if(nums[i] >= H){
                ans = H;
            }
            else{
                break;
            }
        }
        return ans;
    }
};

