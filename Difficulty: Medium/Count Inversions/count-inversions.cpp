class Solution {
public:
    int countAndMerge(vector<int>& arr, int l, int mid, int r) {
        int i = l, j = mid + 1;
        vector<int> temp;
        int cnt = 0;

        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                cnt += (mid - i + 1);
                temp.push_back(arr[j++]);
            }
        }

        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= r) temp.push_back(arr[j++]);

        for (int k = l; k <= r; k++) {
            arr[k] = temp[k - l];
        }

        return cnt;
    }

    int solve(vector<int>& arr, int l, int r) {
        if (l >= r) return 0;

        int mid = (l + r) / 2;

        int count = 0;
        count += solve(arr, l, mid);
        count += solve(arr, mid + 1, r);
        count += countAndMerge(arr, l, mid, r);

        return count;
    }

    int inversionCount(vector<int> &arr) {
        return solve(arr, 0, arr.size() - 1);
    }
};
