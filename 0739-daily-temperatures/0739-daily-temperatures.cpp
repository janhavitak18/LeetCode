class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int>  ans(n);
        stack<int> mono;
        for(int i = n-1; i>=0 ; i--){
            while((!mono.empty()) && arr[mono.top()] <= arr[i]) {
                mono.pop();
            }
             if (mono.empty()) {
                ans[i] = 0;
            }
            else ans[i] = mono.top()-i;
            mono.push(i);
            
        }
        return ans;
        
    }
};