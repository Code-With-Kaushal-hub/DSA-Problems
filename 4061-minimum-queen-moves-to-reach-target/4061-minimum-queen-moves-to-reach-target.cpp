class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0];
        int sc = source[1];

        int dr = target[0];
        int dc = target[1];

        // Same position
        if (sr == dr && sc == dc)
            return 0;

        // Same row, column, or diagonal
        if (sr == dr ||
            sc == dc ||
            abs(sr - dr) == abs(sc - dc))
            return 1;

        // Otherwise, at most 2 moves
        return 2;
    }
};