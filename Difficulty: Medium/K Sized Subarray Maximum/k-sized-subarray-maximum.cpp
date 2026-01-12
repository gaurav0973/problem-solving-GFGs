class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> dq;
        int l = 0, r = 0;
        int n = arr.size();

        while (r < n) {

            // step-1 => r ka niptao
            while (!dq.empty() && arr[r] > arr[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(r);

            // window size control
            if (r - l + 1 > k) {
                if (dq.front() <= l) {
                    dq.pop_front();
                }
                l++;
            }

            // window valid
            if (r - l + 1 == k) {
                ans.push_back(arr[dq.front()]);
            }

            r++;
        }

        return ans;
    }
};
