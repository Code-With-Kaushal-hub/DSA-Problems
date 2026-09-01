class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0], sc = source[1];
        int tr = target[0], tc = target[1];

        // Different colored squares can never be reached
        if ((sr + sc) % 2 != (tr + tc) % 2) return -1;

        // Same square (not possible per constraints, but safe to handle)
        if (sr == tr && sc == tc) return 0;

        // Same diagonal -> reachable in a single move
        if (sr - sc == tr - tc || sr + sc == tr + tc) return 1;

        // Same color, not on a shared diagonal -> always reachable in 2 moves
        return 2;
    }
};