class Solution {
public:
    unordered_map<char, int> m;

    void fun(string &s, string &t, int i) {
        if (i == s.size())
            return;

        m[s[i]]++;      // Add current character of s
        m[t[i]]--;      // Remove current character of t

        if (m[s[i]] == 0)
            m.erase(s[i]);

        if (m.count(t[i]) && m[t[i]] == 0)
            m.erase(t[i]);

        fun(s, t, i + 1);
    }

    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        fun(s, t, 0);

        return m.empty();
    }
};