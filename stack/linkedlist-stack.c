#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure
typedef struct {
    Node* top;
    int size;
} Stack;

// Initialize stack
void initStack(Stack* s) {
    s->top = NULL;
    s->size = 0;
    printf("Stack initialized\n");
}

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Check if stack is empty
bool isEmpty(Stack* s) {
    return s->top == NULL;
}

// Get current size of stack
int size(Stack* s) {
    return s->size;
}

// Push element onto stack
bool push(Stack* s, int value) {
    Node* newNode = createNode(value);
    if (newNode == NULL) {
        printf("Stack Overflow! Memory allocation failed.\n");
        return false;
    }
    
    // Add new node at the top
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
    
    printf("%d pushed to stack\n", value);
    return true;
}

// Pop element from stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop from empty stack.\n");
        return -1;
    }
    
    Node* temp = s->top;
    int poppedValue = temp->data;
    
    // Move top to next node
    s->top = s->top->next;
    
    // Free the old top node
    free(temp);
    s->size--;
    
    printf("Popped %d from stack\n", poppedValue);
    return poppedValue;
}

// Peek at top element without removing
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! No top element.\n");
        return -1;
    }
    
    return s->top->data;
}

// print all elements in the stack
void print(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    
    printf("Stack contents (top to bottom): ");
    Node* temp = s->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->next != NULL) {
            printf("-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Search for an element in the stack
int search(Stack* s, int value) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    
    Node* temp = s->top;
    int position = 0;
    
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d from top\n", value, position);
            return position;
        }
        temp = temp->next;
        position++;
    }
    
    printf("Value %d not found in stack\n", value);
    return -1;
}

// Clear all elements from stack
void clearStack(Stack* s) {
    Node* current = s->top;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    s->top = NULL;
    s->size = 0;
    printf("Stack cleared successfully\n");
}

// Main function to demonstrate stack operations
int main() {
    Stack s;
    initStack(&s);
    
    printf("\n=== Stack using Linked List Demo ===\n\n");
    
    // Push operations
    printf("--- Push Operations ---\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    
    printf("\n");
    print(&s);
    
    // Peek operation
    printf("--- Peek Operation ---\n");
    printf("Top element (without removing): %d\n\n", peek(&s));
    
    // Pop operations
    printf("--- Pop Operations ---\n");
    pop(&s);
    pop(&s);
    
    printf("\n");
    print(&s);
    
    // Search operation
    printf("--- Search Operations ---\n");
    search(&s, 20);
    search(&s, 100);
    printf("\n");
    
    // Push more elements
    printf("--- Adding More Elements ---\n");
    push(&s, 60);
    push(&s, 70);
    push(&s, 80);
    
    printf("\n");
    print(&s);
    
    // Pop all elements
    printf("--- Popping All Elements ---\n");
    while (!isEmpty(&s)) {
        pop(&s);
    }
    
    printf("\n");
    print(&s);
    
    // Try to pop from empty stack
    printf("--- Testing Underflow ---\n");
    pop(&s);
    
    printf("\n--- Adding Elements Again ---\n");
    push(&s, 100);
    push(&s, 200);
    push(&s, 300);
    print(&s);
    
    // Clear stack
    printf("\n--- Clearing Stack ---\n");
    clearStack(&s);
    print(&s);
    
    return 0;
}