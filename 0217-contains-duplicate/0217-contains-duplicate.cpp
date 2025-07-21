class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int k : nums){
            if(++mp[k]>1){
return true;
            }
        }
        return false;
    }
};