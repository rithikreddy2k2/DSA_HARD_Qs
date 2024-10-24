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
};


