class Solution {
  public:
    int getCount(vector<int> &arr, int num1, int num2) {
        // Your code goes here.
        int n = arr.size();
        int start = 0, end = n-1;
        while(start < n){
            if(arr[start] == num1)
                break;
            start++;
        }
        
        while(end >=0){
            if(arr[end] == num2)
                break;
            end--;
        }
        
        if(start >= end)
            return 0;
        
        return end - start - 1;
    }
    
};