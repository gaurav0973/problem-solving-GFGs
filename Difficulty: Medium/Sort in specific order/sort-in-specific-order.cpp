class Solution {
public:
    void sortIt(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            bool aOdd = a % 2;
            bool bOdd = b % 2;
            
            if (aOdd && bOdd) {
                // Both odd → descending
                return a > b;
            } else if (!aOdd && !bOdd) {
                // Both even → ascending
                return a < b;
            } else {
                // One odd, one even → odd first
                return aOdd > bOdd;
            }
        });
    }
};