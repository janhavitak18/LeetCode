
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int maxArea = 0;
        int index = 0;

        while (index < heights.size()) {
            if (s.empty() || heights[index] >= heights[s.top()]) {
                s.push(index++);
            } else {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? index : index - s.top() - 1;
                maxArea = max(maxArea, height * width);
            }
        }

        return maxArea;
    }
};