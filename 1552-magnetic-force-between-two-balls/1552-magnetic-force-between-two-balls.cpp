class Solution {
public:
    bool fun(vector<int>& arr, int dist, int k) {
        int cows = 1,last = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] -last >= dist) {
                cows++;
                last = arr[i];
            }
        }

        return cows >= k;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());  

        int low = 1;
        int high = position.back() - position.front();
        int ans =0;

        while (low <= high) {

            int mid = low +(high - low) / 2;

            if (fun(position, mid, m)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};