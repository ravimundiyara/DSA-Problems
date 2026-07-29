# 238. Product of Array Except Self

## Problem Link

https://leetcode.com/problems/product-of-array-except-self/

---

# Intuition

For every index, we need the product of all elements except the current one.

A straightforward idea is to multiply all the other elements for each index, but this repeats a lot of work.

A better approach is to precompute:

* The product of all elements to the left of each index.
* The product of all elements to the right of each index.

The answer for any index is simply:

`Left Product × Right Product`

We can further optimize the space by storing the left products directly in the answer array and using a single variable to keep track of the right product while traversing from right to left.

---

# Approach

## Brute Force

For every index:

1. Traverse the entire array.
2. Multiply every element except the current one.
3. Store the result.

### Time Complexity

**O(n²)**

### Space Complexity

**O(1)** (excluding the output array)

---

## Better Approach (Prefix & Suffix Arrays)

1. Create a prefix array where `prefix[i]` stores the product of all elements before `i`.
2. Create a suffix array where `suffix[i]` stores the product of all elements after `i`.
3. Multiply `prefix[i] * suffix[i]` to get the answer.

### Time Complexity

**O(n)**

### Space Complexity

**O(n)**

---

## Most Optimal Approach (Constant Extra Space)

1. Store prefix products directly in the answer array.
2. Traverse from right to left while maintaining a running suffix product.
3. Multiply the current answer with the suffix product.
4. Update the suffix product.

No separate prefix or suffix arrays are required.

### Time Complexity

**O(n)**

### Space Complexity

**O(1)** (excluding the output array)

---

# Code (C++)

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Prefix products
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Suffix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};
```

---

# Complexity

**Time Complexity:** O(n)

**Space Complexity:** O(1) (excluding the output array)

---

# Key Learnings

* Prefix Product
* Suffix Product
* Space Optimization
* Array Traversal
* Constant Extra Space Technique

