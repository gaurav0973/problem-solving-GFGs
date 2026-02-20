class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        
        vector<string> nums;
        for (int x : arr) 
            nums.push_back(to_string(x));
    
        sort(nums.begin(), nums.end(), [](string &x, string &y) {
            return x + y > y + x;
        });
        
        if (nums[0] == "0") return "0";
    

        string ans = "";
        for (auto &s : nums) ans += s;
    
        return ans;
        
    }
};