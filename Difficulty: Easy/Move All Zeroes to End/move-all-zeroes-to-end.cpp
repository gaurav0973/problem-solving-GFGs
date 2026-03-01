
// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        uint f = -1;
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                f = i;
                break;
            }
        }
        if(f == -1)
            return;
            
        int s = f + 1;
        while(s < n){
            if(arr[s] == 0){
                s++;
            }
            else{
                swap(arr[f], arr[s]);
                f++;
                s++;
            }
        }
    }
};

