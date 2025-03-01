class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = nums[i] * 2;
                nums[i + 1] = 0;
            }
        }
        int l = 0;
            for (int r = 0; r < n; r++) {
                if (nums[r] != 0) {
                    swap(nums[r], nums[l]);
                    l++;
                }
            }
        return nums;
    }
    
};