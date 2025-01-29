class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int maxArea = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
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
