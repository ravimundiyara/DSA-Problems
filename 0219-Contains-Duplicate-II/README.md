# 219. Contains Duplicate II

## Problem Link

https://leetcode.com/problems/contains-duplicate-ii/

---

# Intuition

The problem asks whether there are two equal elements whose indices differ by at most **k**.

A brute-force approach would compare every pair of elements and check both:

* Are the values equal?
* Is the distance between their indices less than or equal to **k**?

However, this takes too much time for large arrays.

A better idea is to remember the last index where every number appeared. Whenever we encounter the same number again, we simply check whether the difference between the current index and its previous index is at most **k**.

---

# Approach

## Brute Force

Compare every pair of elements.

1. Traverse every index `i`.
2. Traverse every index `j > i`.
3. If `nums[i] == nums[j]` and `j - i <= k`, return `true`.
4. If no such pair exists, return `false`.

### Time Complexity

**O(n²)**

### Space Complexity

**O(1)**

---

## Optimal Approach (Hash Map)

Use an unordered_map to store the latest index of every element.

1. Traverse the array.
2. If the current element has appeared before:

   * Compute the difference between the current index and the stored index.
   * If the difference is at most `k`, return `true`.
3. Update the latest index of the current element.
4. If the traversal completes, return `false`.

### Time Complexity

**O(n)**

### Space Complexity

**O(n)**

---

# Code (C++)

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex;

        for (int i = 0; i < nums.size(); i++) {
            if (lastIndex.find(nums[i]) != lastIndex.end()) {
                if (i - lastIndex[nums[i]] <= k)
                    return true;
            }

            lastIndex[nums[i]] = i;
        }

        return false;
    }
};
```

---

# Complexity

**Time Complexity:** O(n)

**Space Complexity:** O(n)

---

# Key Learnings

* Hash Map
* Array Traversal
* Index Tracking
* Time Optimization from O(n²) to O(n)

