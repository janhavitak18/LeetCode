class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;  // Added missing semicolon
        vector<int> op;

        function<void(vector<int>&, int)> recursiveFunction = [&](vector<int>& arr, int i) {
            if (i == arr.size()) {  
                ans.push_back(op);  
                return;  
            }

            recursiveFunction(arr, i + 1);  
            op.push_back(arr[i]);  
            recursiveFunction(arr, i + 1);  
            op.pop_back();  
        };

        recursiveFunction(nums, 0);  // Corrected function call with 'nums'
        return ans;
    }
};
