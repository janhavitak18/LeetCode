class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string op;

        function<void(int, int, int)> fun = [&](int n, int open, int close) {
            if (open < n) {
                op.push_back('(');
                fun(n, open + 1, close);
                op.pop_back();
            }
            if (close < open) { 
                op.push_back(')');
                fun(n, open, close + 1);
                op.pop_back();
            }
            if (open == n && close == n) {
                ans.push_back(op);
                return;
            }
        };

        fun(n, 0, 0);
        return ans;
    }
};
