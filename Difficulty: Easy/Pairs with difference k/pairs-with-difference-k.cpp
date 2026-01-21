// User function template for C++
class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairs(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int cnt = 0;
        unordered_map<int, int> f;
        for(int x : arr) f[x]++;
        
        for(int i=0; i<n; i++){
            int y = arr[i] + k;
            if(f.find(y) != f.end()){
                cnt += f[y];
            }
        }
        return cnt;
    }
};