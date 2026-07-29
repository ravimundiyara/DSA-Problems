# 33. Search in Rotated Sorted Array

## Problem Link

https://leetcode.com/problems/search-in-rotated-sorted-array/

---

# Intuition

A normal Binary Search only works on a fully sorted array. In this problem, the array has been rotated, so one part is sorted while the other may not be.

The key observation is that **at least one half (left or right) is always sorted**.

At each step:

* Identify which half is sorted.
* Check whether the target lies within that sorted half.
* If it does, search that half.
* Otherwise, search the other half.

This allows us to eliminate half of the search space every iteration.

---

# Approach

## Brute Force

Traverse the entire array.

1. Compare each element with the target.
2. If found, return its index.
3. If the traversal finishes without finding the target, return `-1`.

### Time Complexity

**O(n)**

### Space Complexity

**O(1)**

---

## Optimal Approach (Modified Binary Search)

1. Initialize `left = 0` and `right = n - 1`.
2. Compute the middle index.
3. If the middle element is the target, return its index.
4. Check whether the left half is sorted.

   * If it is sorted and the target lies inside it, search the left half.
   * Otherwise, search the right half.
5. Otherwise, the right half must be sorted.

   * If the target lies inside it, search the right half.
   * Otherwise, search the left half.
6. Continue until the target is found or the search space becomes empty.

### Time Complexity

**O(log n)**

### Space Complexity

**O(1)**

---

# Code (C++)

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[left] <= nums[mid]) {

                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }

            }
            // Right half is sorted
            else {

                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }

            }
        }

        return -1;
    }
};
```

---

# Complexity

**Time Complexity:** O(log n)

**Space Complexity:** O(1)

---

# Key Learnings

* Modified Binary Search
* Rotated Sorted Array
* Identifying the Sorted Half
* Divide and Conquer
* Efficient Searching
