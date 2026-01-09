class Solution {
  public:
    int search(vector<int>& arr, int x) {
        int n = arr.size();
        int start = 0, end = n - 1;

        while (start <= end) {
            int guess = start + (end - start) / 2;

            if (arr[guess] == x)
                return guess;

            // part-1 : guess is in left sorted part
            else if (arr[guess] >= arr[0]) {
                if (x >= arr[0] && x < arr[guess])
                    end = guess - 1;
                else
                    start = guess + 1;
            }

            // part-2 : guess is in right sorted part
            else {
                if (x > arr[guess] && x <= arr[n - 1])
                    start = guess + 1;
                else
                    end = guess - 1;
            }
        }
        return -1;
    }
};
