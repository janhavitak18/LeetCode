class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string ans = s;
        for (int i = 0; i<s.size(); i++) {
            for (int j = i+1; j< s.size() ; j++){
                swap(s[i], s[j]);
                ans = max(ans, s);
                swap(s[i], s[j]);
            }
        }
        return stoi(ans);
        
    }
};
