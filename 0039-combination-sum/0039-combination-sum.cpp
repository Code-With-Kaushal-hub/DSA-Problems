class Solution {
public:
    vector<vector<int>> ans;

    void fun(vector<int>& candidates, int target, int i, vector<int>& vec) {
        if (target == 0) {
            ans.push_back(vec);
            return;
        }
        if (i == candidates.size() || target < 0) {
            return;
        }
        vec.push_back(candidates[i]);
        fun(candidates, target - candidates[i], i, vec);
        vec.pop_back();
        fun(candidates, target, i + 1, vec);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> vec;

        fun(candidates, target, 0, vec);

        return ans;
    }
};