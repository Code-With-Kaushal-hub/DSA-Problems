class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        vector<int> result;

        // Count occurrences in nums1
        for (int x : nums1) {
            freq[x]++;
        }

        // Check nums2 and add common elements
        for (int x : nums2) {
            if(freq.count(x)){
                result.push_back(x);
                freq[x]--;
                if(freq[x]==0){
                    freq.erase(x);
                }
            }
        }

        return result;
    }
};

