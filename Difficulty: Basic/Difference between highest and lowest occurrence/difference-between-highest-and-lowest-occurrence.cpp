class Solution {
public:
    int findDiff(vector<int>& arr) {
        // If array is empty or has only one element
        if (arr.size() <= 1) return 0;
        
        // Count frequencies using unordered_map
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        
        // If only one unique element
        if (freq.size() == 1) return 0;
        
        // Find min and max frequencies
        int minFreq = INT_MAX;
        int maxFreq = INT_MIN;
        
        for (auto& it : freq) {
            minFreq = min(minFreq, it.second);
            maxFreq = max(maxFreq, it.second);
        }
        
        return maxFreq - minFreq;
    }
};