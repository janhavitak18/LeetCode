class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int c = count(s.begin(), s.end(), '0');
        for (auto i : s) {
            if (i == '0') {
                c--;
            } else {
                ans += c;
            }
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
};
