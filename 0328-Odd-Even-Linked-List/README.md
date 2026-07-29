# 328. Odd Even Linked List

## Problem Link

https://leetcode.com/problems/odd-even-linked-list/

---

# Intuition

The goal is to rearrange the linked list such that all nodes at **odd indices** come first, followed by all nodes at **even indices**, while preserving their original relative order.

A simple approach is to create two separate lists:

* One for odd-indexed nodes.
* One for even-indexed nodes.

Finally, connect the odd list with the even list.

However, this requires extra memory.

A better approach is to rearrange the pointers in-place using two pointers—one for odd nodes and one for even nodes—resulting in **O(1)** extra space.

---

# Approach

## Brute Force

1. Traverse the linked list.
2. Store odd-indexed node values in one vector.
3. Store even-indexed node values in another vector.
4. Rewrite the linked list using both vectors.

### Time Complexity

**O(n)**

### Space Complexity

**O(n)**

---

## Optimal Approach (In-Place Rearrangement)

1. If the list is empty or contains only one node, return it.
2. Initialize:

   * `odd` pointing to the first node.
   * `even` pointing to the second node.
   * `evenHead` to remember the start of the even list.
3. Connect odd nodes together.
4. Connect even nodes together.
5. Continue until the end of the list.
6. Attach the even list after the odd list.

This rearranges the list without creating any new nodes.

### Time Complexity

**O(n)**

### Space Complexity

**O(1)**

---

# Code (C++)

```cpp
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even != nullptr && even->next != nullptr) {

            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};
```

---

# Complexity

**Time Complexity:** O(n)

**Space Complexity:** O(1)

---

# Key Learnings

* Linked List
* Pointer Manipulation
* In-place Rearrangement
* Odd-Even Indexing
* Space Optimization
