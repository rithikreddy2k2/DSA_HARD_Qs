// Largest Rectangle in Histogram: https://leetcode.com/problems/largest-rectangle-in-histogram/
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
            // While the current bar is shorter than the bar at the top of the stack,
            // this means we can no longer extend the rectangle formed by the bar on top.
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];  // Get the height of the top bar.
                st.pop();  // Remove this bar from the stack as we are processing it.

                // Calculate the width of the rectangle:
                // - If the stack is empty, this means the popped bar is the smallest so far,
                //   so it can extend from index 0 to the current index `i`.
                // - Otherwise, the width is the difference between the current index `i`
                //   and the index of the new top of the stack (because the new top is where
                //   the bar is shorter, meaning the rectangle starts right after this index).
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
};
