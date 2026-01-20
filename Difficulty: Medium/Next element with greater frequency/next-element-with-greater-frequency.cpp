class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int,int> f;
        for(int x : arr) f[x]++;
        
        vector<int> ans(n,-1);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            while(st.size() > 0 && f[arr[st.top()]] < f[arr[i]]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
