class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string a = "qwertyuiop";
        string b = "asdfghjkl";
        string c = "zxcvbnm";

        vector<string> ans;

        for (string i : words) {
            int t = 0;
            int x = 0;

            for (char j : i) {
                if (!a.contains(tolower(j))) {
                    t = 1;
                    break;
                } else {
                    x = 1;
                }
            }

            if (x == 1 && t == 0) {
                ans.push_back(i);
                continue;
            }

            t = 0;
            x = 0;

            for (char j : i) {
                if (!b.contains(tolower(j))) {
                    t = 1;
                    break;
                } else {
                    x = 1;
                }
            }

            if (x == 1 && t == 0) {
                ans.push_back(i);
                continue;
            }

            t = 0;
            x = 0;

            for (char j : i) {
                if (!c.contains(tolower(j))) {
                    t = 1;
                    break;
                } else {
                    x = 1;
                }
            }

            if (x == 1 && t == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};