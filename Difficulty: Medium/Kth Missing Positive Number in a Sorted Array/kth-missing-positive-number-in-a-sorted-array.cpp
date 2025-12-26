
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        while(start <= end)
        {
            int mid = (start + end)/2;
            // missing number = arr[mid] - (mid + 1)
            if(k > arr[mid] - (mid+1))
                start = mid + 1;
            else
                end = mid - 1;
        }
        return start + k;
    }
};

