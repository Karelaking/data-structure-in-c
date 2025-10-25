# Stack Implementation in C using Array

A complete implementation of the Stack data structure using arrays in C programming language.

## 📋 Table of Contents
- [What is a Stack?](#what-is-a-stack)
- [Features](#features)
- [How to Use](#how-to-use)
- [Function Reference](#function-reference)
- [Examples](#examples)
- [Complexity Analysis](#complexity-analysis)
- [Limitations](#limitations)
- [Contributing](#contributing)

## 🎯 What is a Stack?

A **Stack** is a linear data structure that follows the **LIFO (Last In First Out)** principle. Think of it like a stack of plates - you can only add or remove plates from the top.

### Real-World Examples:
- Stack of books
- Browser back button (history)
- Undo/Redo functionality in editors
- Function call stack in programming

## ✨ Features

- ✅ **Push Operation** - Add elements to the top
- ✅ **Pop Operation** - Remove elements from the top
- ✅ **Peek Operation** - View top element without removing
- ✅ **Overflow Protection** - Prevents adding to a full stack
- ✅ **Underflow Protection** - Prevents removing from an empty stack
- ✅ **Size Tracking** - Know how many elements are present
- ✅ **Display Function** - View all stack contents
- ✅ **Status Checks** - Check if stack is empty or full

## 🚀 How to Use

### Compilation

```bash
gcc stack.c -o stack
```

### Running the Program

```bash
./stack
```

### In Your Own Code

```c
#include <stdio.h>
#include "stack.h"

int main() {
    Stack s;
    initStack(&s);
    
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    
    printf("Top element: %d\n", peek(&s));
    printf("Popped: %d\n", pop(&s));
    
    display(&s);
    
    return 0;
}
```

## 📖 Function Reference

### `void initStack(Stack *s)`
**Purpose:** Initializes an empty stack  
**Parameters:** Pointer to Stack structure  
**Returns:** Nothing  
**Example:**
```c
Stack s;
initStack(&s);
```

### `bool push(Stack *s, int value)`
**Purpose:** Adds an element to the top of the stack  
**Parameters:** 
- `s` - Pointer to Stack
- `value` - Integer value to push  
**Returns:** `true` if successful, `false` if stack is full  
**Example:**
```c
push(&s, 42);  // Adds 42 to the stack
```

### `int pop(Stack *s)`
**Purpose:** Removes and returns the top element  
**Parameters:** Pointer to Stack  
**Returns:** Top element value, or -1 if stack is empty  
**Example:**
```c
int value = pop(&s);  // Removes and gets top element
```

### `int peek(Stack *s)`
**Purpose:** Returns the top element without removing it  
**Parameters:** Pointer to Stack  
**Returns:** Top element value, or -1 if stack is empty  
**Example:**
```c
int top = peek(&s);  // Just looks at top element
```

### `bool isEmpty(Stack *s)`
**Purpose:** Checks if the stack is empty  
**Parameters:** Pointer to Stack  
**Returns:** `true` if empty, `false` otherwise  
**Example:**
```c
if (isEmpty(&s)) {
    printf("Stack is empty!\n");
}
```

### `bool isFull(Stack *s)`
**Purpose:** Checks if the stack is full  
**Parameters:** Pointer to Stack  
**Returns:** `true` if full, `false` otherwise  
**Example:**
```c
if (isFull(&s)) {
    printf("Cannot add more elements!\n");
}
```

### `int size(Stack *s)`
**Purpose:** Returns the number of elements in the stack  
**Parameters:** Pointer to Stack  
**Returns:** Integer count of elements  
**Example:**
```c
printf("Stack has %d elements\n", size(&s));
```

### `void display(Stack *s)`
**Purpose:** Prints all elements from top to bottom  
**Parameters:** Pointer to Stack  
**Returns:** Nothing  
**Example:**
```c
display(&s);  // Shows: Stack contents (top to bottom): 30 20 10
```

## 💡 Examples

### Example 1: Basic Operations
```c
Stack s;
initStack(&s);

push(&s, 10);
push(&s, 20);
push(&s, 30);

display(&s);  // Output: 30 20 10

int top = pop(&s);
printf("Popped: %d\n", top);  // Output: Popped: 30

display(&s);  // Output: 20 10
```

### Example 2: Checking Stack Status
```c
Stack s;
initStack(&s);

if (isEmpty(&s)) {
    printf("Stack is empty\n");  // This will print
}

push(&s, 100);

printf("Size: %d\n", size(&s));  // Output: Size: 1
printf("Top: %d\n", peek(&s));   // Output: Top: 100
```

### Example 3: Handling Overflow
```c
Stack s;
initStack(&s);

// Trying to push when stack is full
for (int i = 0; i < 101; i++) {
    if (!push(&s, i)) {
        printf("Stack is full at element %d\n", i);
        break;
    }
}
```

## ⚡ Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Push      | O(1)           | O(1)             |
| Pop       | O(1)           | O(1)             |
| Peek      | O(1)           | O(1)             |
| isEmpty   | O(1)           | O(1)             |
| isFull    | O(1)           | O(1)             |
| Size      | O(1)           | O(1)             |
| Display   | O(n)           | O(1)             |

**Overall Space Complexity:** O(MAX) where MAX is the maximum stack size

## ⚠️ Limitations

1. **Fixed Size:** Maximum capacity is set to 100 elements (defined by `MAX`)
2. **Data Type:** Only stores integers (can be modified for other types)
3. **No Dynamic Resizing:** Cannot grow beyond initial capacity
4. **Memory Allocation:** Uses static array allocation

### How to Modify Maximum Size

Change the `MAX` constant at the top of the file:
```c
#define MAX 1000  // Change to desired size
```

## 🔧 Customization

### To Store Different Data Types

Change the array type and function parameters:
```c
// For characters
typedef struct {
    char arr[MAX];
    int top;
} Stack;

// For floating-point numbers
typedef struct {
    float arr[MAX];
    int top;
} Stack;
```

## 📝 License

This implementation is free to use for educational and commercial purposes.

## 🤝 Contributing

Feel free to fork, modify, and improve this implementation. Suggestions for enhancements:
- Add dynamic resizing capability
- Implement using linked lists
- Add more utility functions
- Support for generic data types

## 📧 Questions?

If you have questions about how this stack implementation works, refer to the detailed function explanations in the source code comments.

---

**Happy Coding! 🚀**