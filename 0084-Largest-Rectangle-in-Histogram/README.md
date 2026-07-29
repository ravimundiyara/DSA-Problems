# 84. Largest Rectangle in Histogram

## Problem Link

https://leetcode.com/problems/largest-rectangle-in-histogram/

---

# Intuition

A brute-force solution would consider every bar as the starting point and expand to find the largest rectangle. However, this repeatedly calculates the same information, resulting in a high time complexity.

The key observation is that for every bar, if we know:

* the first smaller element on its left, and
* the first smaller element on its right,

then that bar can be the height of the largest rectangle spanning between those two smaller elements.

A monotonic increasing stack helps us efficiently find these boundaries in linear time.

---

# Approach

## Brute Force

For every bar:

1. Consider it as the minimum height.
2. Expand left until a smaller bar is found.
3. Expand right until a smaller bar is found.
4. Compute the rectangle area.
5. Keep track of the maximum area.

### Time Complexity

**O(n²)**

### Space Complexity

**O(1)**

---

## Better Approach (Previous Smaller & Next Smaller Arrays)

1. Compute the Previous Smaller Element (PSE) for every index using a monotonic stack.

2. Compute the Next Smaller Element (NSE) similarly.

3. Width of the rectangle:

   `width = NSE[i] - PSE[i] - 1`

4. Area:

   `height[i] × width`

5. Return the maximum area.

### Time Complexity

**O(n)**

### Space Complexity

**O(n)**

---

## Most Optimal Approach (Single Monotonic Stack)

Instead of storing separate PSE and NSE arrays:

1. Traverse the histogram.
2. Maintain a monotonic increasing stack of indices.
3. Whenever the current height is smaller than the stack's top, pop elements.
4. Calculate the rectangle area using the popped height.
5. Continue until the histogram is processed.
6. Process the remaining stack elements.

Each index is pushed and popped only once.

### Time Complexity

**O(n)**

### Space Complexity

**O(n)**

---

# Code (C++)

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {

            while (!st.empty() &&
                  (i == n || heights[st.top()] >= heights[i])) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};
```

---

# Complexity

**Time Complexity:** O(n)

**Space Complexity:** O(n)

---

# Key Learnings

* Monotonic Stack
* Previous Smaller Element (PSE)
* Next Smaller Element (NSE)
* Stack-Based Range Problems
* Largest Rectangle Pattern
* Linear Time Optimization
