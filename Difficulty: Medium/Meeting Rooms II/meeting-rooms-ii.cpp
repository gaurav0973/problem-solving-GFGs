class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n = start.size();
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int i=0, j=0, ans = 0, cnt = 0;
        while(i <n && j<end.size()){
            if(start[i] < end[j]){
                cnt++;
                i++;
            }else{
                cnt--;
                j++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
