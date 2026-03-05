class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int l = 0, r = 0;
        int n = s.size();
        int maxLen = -1;
        unordered_map<char,int> f;
        while(r<n)
        {
            // 1. right ko info me le lo
            f[s[r]]++;
            
            // 2. jabtak galat hai => shrink karo 
            while(f.size() > k)
            {
                f[s[l]]--;
                if(f[s[l]] == 0)
                    f.erase(s[l]);
                l++;
            }
            // 3. answer vagar nikalo
            if(f.size() == k)
                maxLen = max(maxLen, r-l+1);
            r++;
        
        }
        return maxLen;
    }
};