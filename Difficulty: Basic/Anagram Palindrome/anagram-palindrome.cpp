int isPossible(string S) {
    // your code here
    int n = S.size();
    unordered_map<char,int> f;
    for(int i=0; i<n; i++){
        f[S[i]]++;
    }
    
    int oddCnt = 0;
    for(auto it : f){
        int cnt = it.second;
        if(cnt%2 ==1)
            oddCnt++;
    }
    return oddCnt <= 1;
}