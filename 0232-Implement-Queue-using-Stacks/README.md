# 232. Implement Queue using Stacks

## Problem Link

https://leetcode.com/problems/implement-queue-using-stacks/

---

# Intuition

A queue follows the **First In First Out (FIFO)** principle, whereas a stack follows **Last In First Out (LIFO)**. Since we only have stacks available, we need a way to simulate queue behavior.

One approach is to use two stacks:

* **Input Stack:** Stores newly pushed elements.
* **Output Stack:** Used when removing or accessing the front element.

Whenever the output stack becomes empty, transfer all elements from the input stack to the output stack. This reverses their order, making the oldest element appear on top, just like a queue.

---

# Approach

## Brute Force (Single Stack)

Using only one stack, every push operation requires rearranging the elements so that the oldest element always stays on top.

1. Push the new element.
2. Move all previous elements below it.
3. Perform pop and peek normally.

### Time Complexity

* Push: **O(n)**
* Pop: **O(1)**
* Peek: **O(1)**

### Space Complexity

**O(n)**

---

## Optimal Approach (Two Stacks)

Maintain two stacks:

* **inputStack** → Used for push operations.
* **outputStack** → Used for pop and peek operations.

Operations:

1. **push(x)**

   * Push `x` into `inputStack`.

2. **pop()**

   * If `outputStack` is empty, move all elements from `inputStack` to `outputStack`.
   * Pop the top element from `outputStack`.

3. **peek()**

   * If `outputStack` is empty, transfer all elements.
   * Return the top element.

4. **empty()**

   * Return true only if both stacks are empty.

This gives an amortized **O(1)** time complexity for all operations.

---

# Code (C++)

```cpp
class MyQueue {
private:
    stack<int> inputStack;
    stack<int> outputStack;

    void transfer() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        if (outputStack.empty())
            transfer();

        int value = outputStack.top();
        outputStack.pop();
        return value;
    }

    int peek() {
        if (outputStack.empty())
            transfer();

        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};
```

---

# Complexity

| Operation | Time           |
| --------- | -------------- |
| Push      | O(1)           |
| Pop       | O(1) Amortized |
| Peek      | O(1) Amortized |
| Empty     | O(1)           |

**Space Complexity:** O(n)

---

# Key Learnings

* Stack
* Queue
* FIFO vs LIFO
* Amortized Analysis
* Data Structure Design
