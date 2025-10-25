#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_MAX 10

// Stack structure
struct Stack {
  int arr[STACK_MAX];
  int size;
};

// Initialize stack
void initStack(struct Stack *s) {
    s->size = -1;
}

// Check if stack is empty
bool isEmpty(struct Stack *s) {
    return s->size == -1;
}

// Check if stack is full
bool isFull(struct Stack *s) {
    return s->size == STACK_MAX - 1;
}

// Push element onto stack
bool push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return false;
    }
    s->arr[++(s->size)] = value;
    printf("%d pushed to stack\n", value);
    return true;
}


// Pop element from stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    return s->arr[(s->size)--];
}

// Peek at top element
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->size];
}

// Get current size of stack
int size(struct Stack *s) {
    return s->size + 1;
}

// print stack contents
void print(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack contents (top to bottom): ");
    for (int i = s->size; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}


// Main function to demonstrate stack operations
int main() {
    struct Stack s;
    initStack(&s);
    
    printf("=== Stack Operations Demo ===\n\n");
    
    // Push elements
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    
    printf("\n");
    print(&s);
    printf("Stack size: %d\n", size(&s));
    printf("Top element: %d\n\n", peek(&s));
    
    // Pop elements
    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));
    
    printf("\n");
    print(&s);
    printf("Stack size: %d\n", size(&s));
    printf("Top element: %d\n\n", peek(&s));
    
    // Push more elements
    push(&s, 60);
    push(&s, 70);
    
    printf("\n");
    print(&s);
    
    // Check stack status
    printf("\nIs stack empty? %s\n", isEmpty(&s) ? "Yes" : "No");
    printf("Is stack full? %s\n", isFull(&s) ? "Yes" : "No");
    
    return 0;
}