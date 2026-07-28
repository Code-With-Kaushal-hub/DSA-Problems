class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;

        int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r - 1;

        while(k--) {

            if(l < 0) {
                ans.push_back(arr[r]);
                r++;
            }
            else if(r >= arr.size()) {
                ans.push_back(arr[l]);
                l--;
            }
            else if(abs(arr[l]-x) <= abs(arr[r]-x)) {
                ans.push_back(arr[l]);
                l--;
            }
            else {
                ans.push_back(arr[r]);
                r++;
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};