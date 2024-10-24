// Maximal Rectangle: https://leetcode.com/problems/maximal-rectangle/description/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Stack to store indices of histogram bars
        stack<int> st;
        
        // Add a sentinel value (0) at the end of the heights array.
        // This ensures all bars in the stack get processed by the end.
        heights.push_back(0); 
        
        int maxArea = 0;  // Variable to track the maximum rectangular area.

        // Iterate through the heights array.
        for (int i = 0; i < heights.size(); ++i) {
            // If the current height is less than the height of the bar at the top of the stack,
            // this means we have reached the boundary where the rectangle can no longer expand
            // for the bar at the top of the stack.
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];  // Get the height of the top bar.
                st.pop();  // Remove this bar from the stack as we are processing it.

                // Calculate the width of the rectangle:
                // If the stack is empty, it means the popped bar can extend from the start (index 0) 
                // up to the current index i.
                // Otherwise, the width is the difference between the current index `i` and 
                // the index of the new top of the stack (which is the first smaller bar on the left).
                int width = st.empty() ? i : i - st.top() - 1;

                // Update the maximum area if the area of the current rectangle is larger.
                maxArea = max(maxArea, height * width);
            }
            // Push the current bar's index onto the stack.
            // This ensures we process the bars in increasing height order.
            st.push(i);
        }

        // Return the maximum area found.
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // Base case: if the matrix is empty, return 0
        if (matrix.empty()) return 0;
        
        // Get the number of rows and columns in the matrix
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Initialize the heights array where each element represents the height of the histogram
        vector<int> heights(cols, 0);
        int maxRectangle = 0;  // Variable to keep track of the maximum rectangle area found
        
        // Iterate over each row in the matrix
        for (int i = 0; i < rows; ++i) {
            // Update the heights array based on the current row
            for (int j = 0; j < cols; ++j) {
                // If the current element is '1', increment the corresponding height by 1
                // If it's '0', reset the height to 0
                if (matrix[i][j] == '1') {
                    heights[j] += 1;  // Increase height if consecutive '1's
                } else {
                    heights[j] = 0;  // Reset height to 0 for '0's
                }
            }
            // After updating the heights, calculate the largest rectangle area for the current row
            maxRectangle = max(maxRectangle, largestRectangleArea(heights));
        }
        
        return maxRectangle;  // Return the largest rectangle area found in the entire matrix
    }
};
