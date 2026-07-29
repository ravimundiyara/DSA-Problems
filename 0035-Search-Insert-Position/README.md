# 35. Search Insert Position

## Problem Link

https://leetcode.com/problems/search-insert-position/

---

# Intuition

The array is already sorted, so instead of scanning every element, we can use **Binary Search** to efficiently locate the target.

If the target exists, return its index.

If it does not exist, Binary Search naturally tells us where the target should be inserted to keep the array sorted.

---

# Approach

## Brute Force

Traverse the array from left to right.

1. If the current element is equal to the target, return its index.
2. If the current element becomes greater than the target, return the current index because this is the correct insertion position.
3. If the traversal completes, insert the target at the end of the array.

### Time Complexity

**O(n)**

### Space Complexity

**O(1)**

---

## Optimal Approach (Binary Search)

Since the array is sorted:

1. Initialize two pointers:

   * `left = 0`
   * `right = n - 1`
2. Find the middle index.
3. If `nums[mid] == target`, return `mid`.
4. If `nums[mid] < target`, search the right half.
5. Otherwise, search the left half.
6. When the loop ends, `left` points to the correct insertion position.

### Time Complexity

**O(log n)**

### Space Complexity

**O(1)**

---

# Code (C++)

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return left;
    }
};
```

---

# Complexity

**Time Complexity:** O(log n)

**Space Complexity:** O(1)

---

# Key Learnings

* Binary Search
* Sorted Array
* Divide and Conquer
* Lower Bound Concept
* Efficient Searching

