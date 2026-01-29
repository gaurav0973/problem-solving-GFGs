class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        //creation of min heap
        priority_queue<int> maxH;

        for(int i=0; i<n; i++){
            maxH.push(arr[i]);
            if(maxH.size() > k){
                maxH.pop();
            }
        }
        return maxH.top();
    }
};