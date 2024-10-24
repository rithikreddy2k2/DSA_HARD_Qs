### Example ###
Input: heights = [2, 1, 5, 6, 2, 3]
Output: 10
  
### Explanation: The largest rectangle can be formed by the bars with heights 5 and 6, giving an area of 10 (5 * 2 = 10) ###

## Understanding the Rectangle in a Histogram ##
Each bar in the histogram has a height, and each occupies a unit width.
We can form a rectangle by choosing any subset of consecutive bars. The height of this rectangle is the smallest height among the selected bars, and the width is determined by how far we can extend the selection.

## Challenge ##
The problem boils down to figuring out, for each bar, how wide we can expand the rectangle while maintaining the height at least as large as the bar in question.
Specifically, for each bar at index i with height heights[i], we want to find the first smaller bar to the left of i and the first smaller bar to the right of i.
  
## Key Idea — Using a Stack to Track Increasing Heights ##
The trick is to use a monotonic stack (a stack that stores elements in increasing order) to efficiently keep track of the heights.
As you traverse the heights, you maintain a stack of indices of bars. For each bar, you either:
Push it onto the stack if it is greater than or equal to the top of the stack.
Pop the stack if you encounter a bar smaller than the one at the top, because it means the current bar is the first smaller bar to the right of the bar at the top of the stack.
When you pop an element from the stack, the one below it becomes the first smaller bar to the left.
This process allows you to compute the width of the rectangle for the popped bar and subsequently its area.
  
## Expanding Width ##
When we pop an element from the stack, the rectangle's width is determined by how far we can extend:
The right boundary is the current bar we just encountered.
The left boundary is the bar that is now on top of the stack after the pop.
If the stack is empty after popping, it means that the popped bar can extend all the way to the beginning of the histogram.
  
## Detailed Example Walkthrough ##
Let's walk through the example [2, 1, 5, 6, 2, 3] step by step:

## Initial Setup ##
We maintain a stack to keep track of indices of heights in increasing order.
As we traverse the array, we perform either a push or pop operation based on the current height.
Step-by-Step Breakdown:
Index 0, height = 2:

The stack is empty, so we push index 0 onto the stack.
Stack: [0]
Index 1, height = 1:

The current height (1) is smaller than the height at the top of the stack (2).
We pop index 0 from the stack, which represents the bar of height 2.
Now we compute the area for the popped bar:
The width is 1 (since there are no bars left in the stack, it extends to the leftmost boundary).
Area = 2 * 1 = 2
Now we push index 1 onto the stack.
Stack: [1]
Index 2, height = 5:

The current height (5) is greater than the height at the top of the stack (1).
We push index 2 onto the stack.
Stack: [1, 2]
Index 3, height = 6:

The current height (6) is greater than the height at the top of the stack (5).
We push index 3 onto the stack.
Stack: [1, 2, 3]
Index 4, height = 2:

The current height (2) is smaller than the height at the top of the stack (6).
We pop index 3 from the stack (height 6):
The width is 1 (since the top of the stack is now 2, and index 3 extends from 3 to 3).
Area = 6 * 1 = 6
The current height (2) is still smaller than the height at the top of the stack (5).
We pop index 2 from the stack (height 5):
The width is 2 (it extends from index 2 to 3).
Area = 5 * 2 = 10
Now we push index 4 onto the stack.
Stack: [1, 4]
Index 5, height = 3:

The current height (3) is greater than the height at the top of the stack (2).
We push index 5 onto the stack.
Stack: [1, 4, 5]
Final Pop Operations (after the array traversal):

We have reached the end of the array, so we need to pop all remaining elements from the stack and calculate their areas.
Pop index 5 (height 3):
The width is 1 (from index 5 to 5).
Area = 3 * 1 = 3
Pop index 4 (height 2):
The width is 4 (from index 1 to 5).
Area = 2 * 4 = 8
Pop index 1 (height 1):
The width is 6 (the entire width of the histogram).
Area = 1 * 6 = 6

The maximum area found is 10.
