class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        int cnt = 0;
        solve(arr, 0, arr.size()-1, cnt);
        return cnt;
        
    }
    
    void solve(vector<int> &arr, int start, int end, int &cnt){
        if(start >= end){
            return;
        }
        
        int mid = (start+end)/2;
        solve(arr, start, mid, cnt);
        solve(arr, mid+1, end, cnt);
        mergeTwoSortedArray(arr, start, mid, end, cnt);
    }
    
    void mergeTwoSortedArray(vector<int>& arr, int start, int mid, int end, int &cnt){
        int i = start;
        int j = mid+1;
        vector<int> temp;
        while(i <= mid && j <= end){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                cnt += (mid - i + 1);
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i <= mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j <= end){
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int i=start; i<=end; i++){
            arr[i] = temp[i-start];
        }
    }
};