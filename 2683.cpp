class Solution {
public:
    bool doesValidArrayExist(vector<int>& der) {
        int res = 0;
        for(int i=0; i<der.size(); i++) res ^= der[i];
        return res == 0 ? true : false;
    }
};
