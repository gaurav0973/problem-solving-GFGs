string reverseString(string s) {
    bool visited[256] = {false};
    string ans = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] != ' ' && !present[s[i]]) {
            ans.push_back(s[i]);
            present[s[i]] = true;
        }
    }
    
    return ans;
}