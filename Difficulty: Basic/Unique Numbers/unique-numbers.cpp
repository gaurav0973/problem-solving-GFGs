class Solution {
public:
    bool hasUniqueDigits(int n) {
        bool visited[10] = {false};
        
        while (n > 0) {
            int digit = n % 10;
            if (visited[digit]) {
                return false;
            }
            visited[digit] = true;
            n /= 10;
        }
        
        return true;
    }
    vector<int> uniqueNumbers(int L, int R) {
        vector<int> result;
        
        for (int num = L; num <= R; num++) {
            if (hasUniqueDigits(num)) {
                result.push_back(num);
            }
        }
        
        return result;
    }
    
};