class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return isAwinning(nums, 0, n - 1, true, 0, 0); 
    }

    bool isAwinning(vector<int>& nums, int pt1, int pt2, bool aturn, int suma, int sumb) {
        if (pt1 > pt2) {
            return suma >= sumb;
        }

        if (aturn) {
           
            return isAwinning(nums, pt1 + 1, pt2, false, suma + nums[pt1], sumb) ||
                   isAwinning(nums, pt1, pt2 - 1, false, suma + nums[pt2], sumb);
        } else {
           
            return isAwinning(nums, pt1 + 1, pt2, true, suma, sumb + nums[pt1]) &&
                   isAwinning(nums, pt1, pt2 - 1, true, suma, sumb + nums[pt2]);
        }
    }
};
