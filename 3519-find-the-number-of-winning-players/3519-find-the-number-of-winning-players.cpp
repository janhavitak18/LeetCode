class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int, unordered_map<int, int>> playerColorCount;
        for (const auto& p : pick) {
            int player = p[0];
            int color = p[1];
            playerColorCount[player][color]++;
        }

        int winners = 0;

        for (int i = 0; i < n; ++i) {
            bool won = false;
            for (const auto& [color, count] : playerColorCount[i]) {
                if (count >= i + 1) {
                    won = true;
                    break;
                }
            }
            if (won) winners++;
        }

        return winners;
    }
};
