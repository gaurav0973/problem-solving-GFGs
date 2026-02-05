class Solution {
  public:
    vector<int> firstNegInt(vector<int>& nums, int k) {
        // write code here
        deque<int> dq;
        vector<int> ans;
        int n = nums.size();
        int l = 0, r = 0;

        while(r <= k-2){
            if(nums[r] < 0)
                dq.push_back(r);
            r++;
        }

        while (r < n) {

            if(nums[r] < 0)
                dq.push_back(r);
            
            while(dq.size()>0 && dq.front() < l){
                dq.pop_front();
            }
            
            if(dq.size() == 0)
                ans.push_back(0);
            else
                ans.push_back(nums[dq.front()]);
            l++;
            r++;
        }

        return ans;
    }
};