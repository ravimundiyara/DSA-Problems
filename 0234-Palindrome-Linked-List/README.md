# 234. Palindrome Linked List

## Problem Link

https://leetcode.com/problems/palindrome-linked-list/

---

# Intuition

A linked list is a palindrome if it reads the same from left to right and right to left.

A straightforward approach is to copy all the node values into an array and then check whether the array is a palindrome using two pointers.

However, this requires extra space.

A more efficient approach is to:

* Find the middle of the linked list.
* Reverse the second half.
* Compare the first half with the reversed second half.
* Restore the list (optional but recommended).

This achieves **O(n)** time with **O(1)** extra space.

---

# Approach

## Brute Force

1. Traverse the linked list and store all node values in a vector.
2. Use two pointers:

   * One at the beginning.
   * One at the end.
3. Compare values until the pointers meet.
4. If any values differ, return `false`.
5. Otherwise, return `true`.

### Time Complexity

**O(n)**

### Space Complexity

**O(n)**

---

## Optimal Approach (Reverse Second Half)

1. Find the middle of the linked list using the slow and fast pointer technique.
2. Reverse the second half of the linked list.
3. Compare nodes from:

   * The beginning of the list.
   * The beginning of the reversed second half.
4. If all corresponding values match, the list is a palindrome.
5. Reverse the second half again to restore the original list (optional).

### Time Complexity

**O(n)**

### Space Complexity

**O(1)**

---

# Code (C++)

```cpp
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;

        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow->next);

        ListNode* firstHalf = head;
        ListNode* temp = secondHalf;

        while (temp) {
            if (firstHalf->val != temp->val) {
                reverseList(secondHalf);
                return false;
            }

            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        reverseList(secondHalf);

        return true;
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
* Fast & Slow Pointers
* In-place Reversal
* Two Pointer Technique
* Space Optimization
