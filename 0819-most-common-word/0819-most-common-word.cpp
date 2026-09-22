class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {

        string s = "";
        unordered_map<string, int> m;

        for (char i : paragraph) {

            if (i == ' ') {
                if (!s.empty()) {
                    m[s]++;
                    s = "";
                }
            }
            else if (i != '!' && i != '?' && i != '\'' &&
                     i != ',' && i != ';' && i != '.') {

                s += tolower(i);
            }
            else {
                // punctuation → finish current word
                if (!s.empty()) {
                    m[s]++;
                    s = "";
                }
            }
        }

        // Add last word
        if (!s.empty()) {
            m[s]++;
        }

        unordered_set<string> ban;

        for (string i : banned) {
            ban.insert(i);
        }

        string ans = "";
        int maxi = 0;

        for (auto i : m) {

            if (!ban.count(i.first) && i.second > maxi) {
                maxi = i.second;
                ans = i.first;
            }
        }

        return ans;
    }
};