class Solution {
public:
    vector<vector<string>> ans;
    vector<string> op;

    vector<vector<string>> partition(string s) {
        fun(s, 0);
        return ans;
    }

    void fun(string s, int i) {
        if (i == s.size()) {
            ans.push_back(op);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            if (ispal(s, i, j)) {
                op.push_back(s.substr(i, j - i + 1));
                fun(s, j + 1);
                op.pop_back(); // backtrack
            }
        }
    }

    bool ispal(string s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
