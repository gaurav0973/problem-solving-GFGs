class Solution {
public:
    int subarrayRanges(vector<int>& arr) {
        int n = arr.size();
        long long sumMax = 0, sumMin = 0;
        stack<int> st;

        // -------- SUM OF MAXIMUMS --------
        // Next Greater Element
        vector<int> nge(n), pge(n);

        // PGE
        while(!st.empty()) st.pop();
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // NGE
        while(!st.empty()) st.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for(int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            sumMax += arr[i] * left * right;
        }

        // -------- SUM OF MINIMUMS --------
        vector<int> nse(n), pse(n);

        // PSE
        while(!st.empty()) st.pop();
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // NSE
        while(!st.empty()) st.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for(int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            sumMin += arr[i] * left * right;
        }

        return (int)(sumMax - sumMin);
    }
};
