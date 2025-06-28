class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        int product = 1;
        if(n==1) return nums[0];
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                product = 1;
            else {
                product *= nums[i];
                result = max(result, product);
            }
        }
        product = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == 0)
                product = 1;
            else {
                product *= nums[i];
                result = max(result, product);
            }
        }
        return result;
    }
};