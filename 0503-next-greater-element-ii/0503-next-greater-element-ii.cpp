class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        vector<int> result(n, -1);
        stack<int> st; 
        for (int i =2* n - 1; i >= 0; i--) {
            int originalidx;
            if (i < n) {
                originalidx = i;
            } else {
                originalidx = i - n;
            }
            while (!st.empty() && a[st.top()] <= a[originalidx]) {
                st.pop();
            }

            if (i < n && !st.empty()) {
                result[originalidx] = a[st.top()];
            }

            st.push(originalidx);
        }

        return result;

        // int n = a.size();
        // vector<int>v(n,-1);

        // stack<int>st;
        // for(int i = 2*n - 1; i >= 0; i--)
        // {
            
        //     while(!st.empty() && (a[i%n] >= st.top()))
        //     {
        //         st.pop();
        //     }

        //     if(!st.empty() && (i < n))
        //     {
        //         v[i] = st.top();
        //     }

        //     st.push(a[i%n]);
        // }

        // return v;
    }
};