class Solution {
public:
    bool canServe(vector<int>& arr) {
        int count5 = 0; // Count of $5 bills
        int count10 = 0; // Count of $10 bills
        
        for (int payment : arr) {
            if (payment == 5) {
                // Customer pays with $5, no change needed
                count5++;
            }
            else if (payment == 10) {
                // Customer pays with $10, need to give $5 change
                if (count5 == 0) {
                    return false; // No $5 bills to give as change
                }
                count5--; // Give one $5 as change
                count10++; // Receive $10
            }
            else { // payment == 20
                // Customer pays with $20, need to give $15 change
                // Two options: give one $10 + one $5 OR three $5
                if (count10 > 0 && count5 > 0) {
                    // Prefer to give one $10 and one $5
                    count10--;
                    count5--;
                }
                else if (count5 >= 3) {
                    // Give three $5 bills
                    count5 -= 3;
                }
                else {
                    return false; // Can't give $15 change
                }
            }
        }
        
        return true;
    }
};