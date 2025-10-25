# Stack Implementation using Linked List in C

A dynamic implementation of the Stack data structure using linked lists in C programming language.

## 📋 Table of Contents
- [What is a Stack?](#what-is-a-stack)
- [Why Use Linked List for Stack?](#why-use-linked-list-for-stack)
- [How It Works](#how-it-works)
- [Features](#features)
- [How to Use](#how-to-use)
- [Function Reference](#function-reference)
- [Visual Examples](#visual-examples)
- [Complexity Analysis](#complexity-analysis)
- [Comparison: Array vs Linked List](#comparison-array-vs-linked-list)

## 🎯 What is a Stack?

A **Stack** is a linear data structure that follows the **LIFO (Last In First Out)** principle. 

**Real-World Analogy:** Think of a stack of plates in a cafeteria:
- New plates are added on top (PUSH)
- Plates are removed from the top (POP)
- You can only see the top plate (PEEK)
- Last plate added is the first one taken

## 🔗 Why Use Linked List for Stack?

### Advantages over Array-Based Stack:

| Feature | Array Stack | Linked List Stack |
|---------|-------------|-------------------|
| **Size** | Fixed (e.g., 100 elements) | Dynamic (unlimited*) |
| **Memory** | Pre-allocated, may waste space | Allocated as needed |
| **Overflow** | Can happen when full | Only when system runs out of memory |
| **Flexibility** | Limited by MAX size | Grows/shrinks automatically |

*Limited only by available system memory

### When to Use Linked List Stack:
- ✅ Don't know maximum size in advance
- ✅ Stack size varies significantly
- ✅ Want to avoid wasting memory
- ✅ Need guaranteed push operations (no overflow)

## 🔧 How It Works

### Internal Structure

```
Stack Structure in Memory:

top pointer
    ↓
  [50|•] → [40|•] → [30|•] → [20|•] → [10|NULL]
   data next  data next  data next  data next  data next
```

Each box represents a **Node** containing:
- `data`: The actual value stored
- `next`: Pointer to the next node

The `top` pointer always points to the most recently added node.

### Push Operation
```
Before Push(60):
top → [50] → [40] → [30] → NULL

After Push(60):
top → [60] → [50] → [40] → [30] → NULL
```

### Pop Operation
```
Before Pop():
top → [60] → [50] → [40] → [30] → NULL

After Pop() [returns 60]:
top → [50] → [40] → [30] → NULL
```

## ✨ Features

- ✅ **Dynamic Size** - No fixed maximum limit
- ✅ **Push Operation** - Add elements to the top
- ✅ **Pop Operation** - Remove elements from the top
- ✅ **Peek Operation** - View top without removing
- ✅ **Search Operation** - Find elements by value
- ✅ **Automatic Memory Management** - Frees memory on pop
- ✅ **Underflow Protection** - Prevents popping from empty stack
- ✅ **Size Tracking** - Always know element count
- ✅ **Statistics Display** - View stack information

## 🚀 How to Use

### Compilation

```bash
gcc stack_linkedlist.c -o stack
```

### Running the Program

```bash
./stack
```

### In Your Own Code

```c
#include <stdio.h>
#include "stack_linkedlist.h"

int main() {
    Stack s;
    initStack(&s);
    
    // Add elements
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    
    // View top
    printf("Top: %d\n", peek(&s));
    
    // Remove element
    int value = pop(&s);
    printf("Popped: %d\n", value);
    
    // Display all
    display(&s);
    
    // Clean up
    clearStack(&s);
    
    return 0;
}
```

## 📖 Function Reference

### `void initStack(Stack* s)`

**What it does:** Prepares a new empty stack for use.

**How it works:**
- Sets `top` pointer to NULL (means empty)
- Sets `size` to 0
- Like getting a fresh empty container ready

**Parameters:** Pointer to Stack structure

**Example:**
```c
Stack s;
initStack(&s);  // Stack is now ready to use
```

---

### `bool push(Stack* s, int value)`

**What it does:** Adds a new element to the top of the stack.

**How it works:**
1. Creates a new node with the given value
2. Makes the new node point to the current top
3. Updates top to point to the new node
4. Increases size by 1

**Visual Step-by-Step:**
```
Step 1: Create new node
[NEW:60|NULL]

Step 2: Link to current top
[NEW:60] → [50] → [40] → NULL

Step 3: Update top pointer
top → [60] → [50] → [40] → NULL
```

**Parameters:** 
- `s` - Pointer to Stack
- `value` - Integer to add

**Returns:** `true` if successful, `false` if memory allocation fails

**Example:**
```c
push(&s, 42);  // Adds 42 to top of stack
```

---

### `int pop(Stack* s)`

**What it does:** Removes and returns the top element from the stack.

**How it works:**
1. Checks if stack is empty (underflow protection)
2. Saves the top node's data
3. Moves top pointer to the next node
4. Frees the memory of the removed node
5. Decreases size by 1
6. Returns the saved data

**Visual Step-by-Step:**
```
Before Pop:
top → [60] → [50] → [40] → NULL
       ↑ (save this value)

After Pop:
      [60] (freed from memory)
top → [50] → [40] → NULL
Returns: 60
```

**Parameters:** Pointer to Stack

**Returns:** Value of popped element, or -1 if stack is empty

**Example:**
```c
int value = pop(&s);  // Removes and gets top element
printf("Removed: %d\n", value);
```

---

### `int peek(Stack* s)`

**What it does:** Returns the top element WITHOUT removing it.

**How it works:**
1. Checks if stack is empty
2. Returns the data from the top node
3. Doesn't modify the stack at all

**Visual:**
```
Stack remains unchanged:
top → [60] → [50] → [40] → NULL
       ↑ (just look at this)
Returns: 60
```

**Parameters:** Pointer to Stack

**Returns:** Value at top, or -1 if empty

**Example:**
```c
int top = peek(&s);  // Look at top without removing
printf("Top is: %d\n", top);
```

---

### `bool isEmpty(Stack* s)`

**What it does:** Checks if the stack has any elements.

**How it works:**
- If `top` is NULL → stack is empty → returns `true`
- If `top` points to a node → stack has elements → returns `false`

**Visual:**
```
Empty Stack:
top → NULL     (isEmpty returns true)

Non-Empty Stack:
top → [50] → [40] → NULL     (isEmpty returns false)
```

**Parameters:** Pointer to Stack

**Returns:** `true` if empty, `false` otherwise

**Example:**
```c
if (isEmpty(&s)) {
    printf("Stack is empty!\n");
}
```

---

### `int size(Stack* s)`

**What it does:** Returns the current number of elements in the stack.

**How it works:**
- Simply returns the `size` variable
- This variable is automatically updated with each push/pop

**Parameters:** Pointer to Stack

**Returns:** Integer count of elements

**Example:**
```c
printf("Stack has %d elements\n", size(&s));
```

---

### `void display(Stack* s)`

**What it does:** Prints all elements from top to bottom.

**How it works:**
1. Starts at the top node
2. Prints each node's data
3. Follows the `next` pointers until reaching NULL
4. Shows the visual flow with arrows

**Visual Output:**
```
Stack contents (top to bottom): 60 -> 50 -> 40 -> 30 -> 20
```

**Parameters:** Pointer to Stack

**Example:**
```c
display(&s);  // Shows entire stack
```

---

### `int search(Stack* s, int value)`

**What it does:** Finds a value in the stack and returns its position from the top.

**How it works:**
1. Starts from top (position 0)
2. Checks each node's data
3. If found, returns the position
4. If not found after checking all nodes, returns -1

**Visual:**
```
Stack: 60 -> 50 -> 40 -> 30
       ↑     ↑     ↑     ↑
     pos0  pos1  pos2  pos3

search(&s, 40) returns 2
search(&s, 99) returns -1 (not found)
```

**Parameters:**
- `s` - Pointer to Stack
- `value` - Value to search for

**Returns:** Position from top (0-indexed), or -1 if not found

**Example:**
```c
int pos = search(&s, 30);
if (pos != -1) {
    printf("Found at position %d\n", pos);
}
```

---

### `void clearStack(Stack* s)`

**What it does:** Removes all elements and frees all memory.

**How it works:**
1. Traverses the entire linked list
2. Frees each node one by one
3. Sets top to NULL
4. Sets size to 0

**Visual:**
```
Before Clear:
top → [60] → [50] → [40] → NULL

After Clear:
top → NULL
(all nodes freed from memory)
```

**Parameters:** Pointer to Stack

**Example:**
```c
clearStack(&s);  // Removes everything and frees memory
```

---

### `void displayStats(Stack* s)`

**What it does:** Shows comprehensive information about the stack.

**How it works:**
Displays:
- Current size
- Whether stack is empty
- Top element (if not empty)

**Example Output:**
```
--- Stack Statistics ---
Size: 5
Is Empty: No
Top Element: 60
------------------------
```

**Parameters:** Pointer to Stack

**Example:**
```c
displayStats(&s);  // Show detailed information
```

---

## 💡 Visual Examples

### Example 1: Building a Stack

```c
Stack s;
initStack(&s);

// Start: Empty
top → NULL

push(&s, 10);
// Now: top → [10] → NULL

push(&s, 20);
// Now: top → [20] → [10] → NULL

push(&s, 30);
// Now: top → [30] → [20] → [10] → NULL

display(&s);
// Output: Stack contents (top to bottom): 30 -> 20 -> 10
```

### Example 2: Pop Operations

```c
// Starting state:
// top → [30] → [20] → [10] → NULL

int val1 = pop(&s);  // Returns 30
// Now: top → [20] → [10] → NULL

int val2 = pop(&s);  // Returns 20
// Now: top → [10] → NULL

printf("Popped: %d, %d\n", val1, val2);  // Output: 30, 20
```

### Example 3: Peek vs Pop

```c
// Starting state:
// top → [50] → [40] → [30] → NULL

int peekVal = peek(&s);  // Returns 50
// Stack unchanged: top → [50] → [40] → [30] → NULL

int popVal = pop(&s);    // Returns 50
// Stack changed: top → [40] → [30] → NULL

// Both returned 50, but only pop modified the stack
```

### Example 4: Handling Empty Stack

```c
Stack s;
initStack(&s);

if (isEmpty(&s)) {
    printf("Stack is empty\n");  // This prints
}

int result = pop(&s);  // Prints error message
// Output: "Stack Underflow! Cannot pop from empty stack."
// Returns: -1
```

### Example 5: Memory Management

```c
// Add many elements
for (int i = 1; i <= 1000; i++) {
    push(&s, i);  // No overflow! Grows dynamically
}

printf("Size: %d\n", size(&s));  // Output: Size: 1000

// Remove all elements
clearStack(&s);  // All memory freed properly

printf("Size: %d\n", size(&s));  // Output: Size: 0
```

## ⚡ Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Push      | O(1)           | O(1)             |
| Pop       | O(1)           | O(1)             |
| Peek      | O(1)           | O(1)             |
| isEmpty   | O(1)           | O(1)             |
| Size      | O(1)           | O(1)             |
| Search    | O(n)           | O(1)             |
| Display   | O(n)           | O(1)             |
| Clear     | O(n)           | O(1)             |

**Overall Space Complexity:** O(n) where n is the number of elements

**Note:** All primary stack operations (push, pop, peek) are O(1) - constant time!

## 🆚 Comparison: Array vs Linked List

### Array-Based Stack
```c
// Fixed size
#define MAX 100
int arr[MAX];  // Pre-allocated

// Pros:
✅ Simple implementation
✅ Fast access (no pointer dereferencing)
✅ Cache-friendly (contiguous memory)

// Cons:
❌ Fixed maximum size
❌ Wastes memory if not full
❌ Stack overflow possible
```

### Linked List Stack
```c
// Dynamic size
Node* top;  // Allocated as needed

// Pros:
✅ No size limit (dynamic)
✅ No wasted memory
✅ No stack overflow (except out of memory)
✅ Flexible sizing

// Cons:
❌ Extra memory for pointers
❌ Slightly slower (pointer operations)
❌ Not cache-friendly (scattered memory)
```

### When to Use Which?

**Use Array-Based Stack when:**
- Maximum size is known and small
- Performance is critical
- Memory is allocated in advance anyway

**Use Linked List Stack when:**
- Size is unknown or varies greatly
- Want to avoid memory waste
- Need guaranteed push operations
- Building general-purpose library

## 🔍 Common Use Cases

1. **Function Call Stack** - Programming languages use stacks for function calls
2. **Undo/Redo Operations** - Text editors, graphics programs
3. **Expression Evaluation** - Calculators, compilers
4. **Backtracking Algorithms** - Maze solving, puzzle games
5. **Browser History** - Back button functionality
6. **Syntax Parsing** - Checking balanced parentheses

## 🐛 Common Mistakes to Avoid

### Mistake 1: Forgetting to Initialize
```c
Stack s;
// Missing: initStack(&s);
push(&s, 10);  // ❌ Undefined behavior!
```

**Solution:**
```c
Stack s;
initStack(&s);  // ✅ Always initialize first!
push(&s, 10);
```

### Mistake 2: Not Checking isEmpty Before Pop
```c
int value = pop(&s);  // ❌ What if stack is empty?
```

**Solution:**
```c
if (!isEmpty(&s)) {
    int value = pop(&s);  // ✅ Safe!
}
```

### Mistake 3: Memory Leak - Not Clearing
```c
// ❌ Exiting without clearing
return 0;  // Memory leak!
```

**Solution:**
```c
clearStack(&s);  // ✅ Free all memory
return 0;
```

## 📝 Practice Exercises

1. **Reverse a String** - Push each character, then pop to reverse
2. **Check Balanced Parentheses** - Use stack to match opening/closing brackets
3. **Evaluate Postfix Expression** - Use stack for operands
4. **Convert Decimal to Binary** - Push remainders, pop to get binary

## 🤝 Contributing

Suggestions for improvements:
- Add support for different data types (generic stack)
- Implement stack using doubly linked list
- Add sorting functionality
- Create iterative and recursive versions

## 📧 Need Help?

Common questions answered in the code comments. For more complex queries, refer to data structures textbooks or online resources.

---

**Happy coding! 📚**