#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init(Stack *s, int capacity) {
    s->arr = (int*)malloc(capacity * sizeof(int));
    s->top = -1;
    s->capacity = capacity;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == s->capacity - 1;
}

void resize(Stack *s) {
    s->capacity *= 2;
    s->arr = (int *)realloc(s->arr, s->capacity * sizeof(int));
    printf("Stack resized to capacity %d\n", s->capacity);
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        resize(s); 
    }
    s->arr[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}

int size(Stack *s) {
    return s->top + 1;
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

void clear(Stack *s) {
    s->top = -1;
    printf("Stack cleared\n");
}

void reverse(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty, cannot reverse.\n");
        return;
    }
    int start = 0, end = s->top;
    while (start < end) {
        int temp = s->arr[start];
        s->arr[start] = s->arr[end];
        s->arr[end] = temp;
        start++;
        end--;
    }
    printf("Stack reversed.\n");
}

void search(Stack *s, int value) {
    for (int i = s->top; i >= 0; i--) {
        if (s->arr[i] == value) {
            printf("Value %d found at position %d from top.\n", value, s->top - i + 1);
            return;
        }
    }
    printf("Value %d not found in stack.\n", value);
}

int bottom(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->arr[0];
}

void copyStack(Stack *source, Stack *dest) {
    init(dest, source->capacity);
    dest->top = source->top;
    for (int i = 0; i <= source->top; i++) {
        dest->arr[i] = source->arr[i];
    }
    printf("Stack copied successfully.\n");
}

int sumStack(Stack *s) {
    int sum = 0;
    for (int i = 0; i <= s->top; i++) {
        sum += s->arr[i];
    }
    return sum;
}
