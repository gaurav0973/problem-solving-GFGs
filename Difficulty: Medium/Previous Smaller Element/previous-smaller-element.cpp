class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for(int i=n-1; i>=0; i--){
            
            while(st.size() > 0 && arr[i] < arr[st.top()]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};