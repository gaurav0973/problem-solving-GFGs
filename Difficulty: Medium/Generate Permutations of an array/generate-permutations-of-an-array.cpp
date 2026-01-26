class Solution {
public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> result;
        backtrack(arr, 0, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& arr, int start, vector<vector<int>>& result) {
        if (start == arr.size()) {
            result.push_back(arr);
            return;
        }
        
        for (int i = start; i < arr.size(); i++) {
            swap(arr[start], arr[i]);      // choose
            backtrack(arr, start + 1, result);  // explore
            swap(arr[start], arr[i]);      // unchoose (backtrack)
        }
    }
};