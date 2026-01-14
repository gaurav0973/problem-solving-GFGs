class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        vector<int> police, thieves;
        int n = arr.size();
        
        // Collect indices of police and thieves
        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P') {
                police.push_back(i);
            } else if (arr[i] == 'T') {
                thieves.push_back(i);
            }
        }
        
        int i = 0, j = 0;
        int ans = 0;
        
        // Greedy matching using two pointers
        while (i < police.size() && j < thieves.size()) {
            if (abs(police[i] - thieves[j]) <= k) {
                // Current police can catch current thief
                ans++;
                i++;
                j++;
            } else if (police[i] < thieves[j]) {
                // Current police is too left to catch any thief
                i++;
            } else {
                // Current thief is too left to be caught by any police
                j++;
            }
        }
        
        return ans;
    }
};