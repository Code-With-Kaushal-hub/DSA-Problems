class Solution {
public:
    int fun(int n, vector<int>& vec) {

        if (n ==0)
            return 1;

        if (n == 1)
            return 1;

        if (vec[n -1] != -1)
            return vec[n - 1];

        int l = fun(n -1, vec);
        int r = fun(n -2, vec);

        vec[n-1] = l + r;

        return vec[n -1];
    }

    int climbStairs(int n) {
        vector<int> vec(n, -1);
        return fun(n, vec);
    }
};