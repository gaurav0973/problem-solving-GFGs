class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        int low = 0, high = arr.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == k) {
                return mid;  // Found the element
            }
            else if (arr[mid] < k) {
                low = mid + 1;  // Search in right half
            }
            else {
                high = mid - 1;  // Search in left half
            }
        }
        return low;
    }
};