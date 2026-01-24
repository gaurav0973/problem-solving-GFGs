class Solution {
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if (l >= r) 
            return;
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        mergeTwoSortedArray(arr, l, mid, r);
    }
    
    void mergeTwoSortedArray(vector<int>& arr, int start, int mid, int end){
        int i = start;
        int j = mid+1;
        vector<int> temp;
        while(i <= mid && j <= end){
            if(arr[i] < arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
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