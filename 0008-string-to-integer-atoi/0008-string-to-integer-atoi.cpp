class Solution {
public:
    int myAtoi(string s) {
        long long digit = 0;
        int si =1;
        int i = 0;

        // Skip leading spaces
        while (i < s.size()&& s[i] == ' ')
            i++;

        // Check sign
        if (i < s.size() && (s[i] == '+'|| s[i] == '-')) {
            if (s[i] == '-')
                si=-1;
            i++;
        }

        // Read digits
        while (i < s.size() && isdigit(s[i])) {
            digit = digit * 10 +(s[i] - '0');

            // Overflow check
            if (si== 1 && digit >INT_MAX)
                return INT_MAX;

            if (si== -1 && -digit <INT_MIN)
                return INT_MIN;

            i++;
        }

        return si* digit;
    }
};