class Solution {
public:
    string minWindow(string s, string t) {

        map<char, int> m1;
        map<char, int> m2;

        for (char ch : t) {
            m1[ch]++;
        }

        int l = 0;
        int r = 0;
        int p = 0;
        int mit = INT_MAX;
        int start = 0;

        while (r < s.size()) {

            if (m1.contains(s[r])) {
                m2[s[r]]++;

                if (m2[s[r]] <= m1[s[r]]) {
                    p++;
                }
            }

            while (p == t.size()) {

                if (r - l + 1 < mit) {
                    mit = r - l + 1;
                    start = l;
                }

                if (m1.contains(s[l])) {
                    m2[s[l]]--;

                    if (m2[s[l]] < m1[s[l]]) {
                        p--;
                    }
                }

                l++;
            }

            r++;
        }

        if (mit == INT_MAX) {
            return "";
        }

        return s.substr(start, mit);
    }
};