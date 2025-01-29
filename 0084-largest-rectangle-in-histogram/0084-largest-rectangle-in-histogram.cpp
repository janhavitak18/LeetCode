#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left = getLeft(heights, n);
        vector<int> right = getRight(heights, n);
        int res = 0;

        for(int i = 0; i < n; i++) {
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        }
        return res;
    }

private:
    vector<int> getLeft(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> left(n);

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return left;
    }

    vector<int> getRight(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> right(n);

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return right;
    }
};
