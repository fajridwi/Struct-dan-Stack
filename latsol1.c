#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char alphabet;
    struct Node* link;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, Node* node) {
    node->link = stack->top;
    stack->top = node;
}

Node* pop(Stack* stack) {
    if (stack->top == NULL) {
        return NULL;
    }
    Node* temp = stack->top;
    stack->top = stack->top->link;
    temp->link = NULL;
    return temp;
}

int main() {
    Node l1, l2, l3, l4, l5, l6, l7, l8, l9;
    
    l1.alphabet = 'F';
    l1.link = NULL;
    
    l2.alphabet = 'M';
    l2.link = NULL;
    
    l3.alphabet = 'A';
    l3.link = NULL;
    
    l4.alphabet = 'I';
    l4.link = NULL;

    l5.alphabet = 'K';
    l5.link = NULL;
    
    l6.alphabet = 'T';
    l6.link = NULL;
    
    l7.alphabet = 'N';
    l7.link = NULL;
    
    l8.alphabet = 'O';
    l8.link = NULL;
    
    l9.alphabet = 'R';
    l9.link = NULL;

    Stack* stack = createStack();

    int countI = 0, countA = 0, countK = 0;

    push(stack, &l3);
    push(stack, &l5);
    push(stack, &l4);
    push(stack, &l6);
    push(stack, &l3);
    push(stack, &l2);
    push(stack, &l9);
    push(stack, &l8);
    push(stack, &l1);
    push(stack, &l7);
    push(stack, &l4);

    printf("KATA: ");
    while (stack->top != NULL) {
        Node* current = pop(stack);
        if (current->alphabet == 'I') {
            printf("%c", current->alphabet);
            countI++;
            if (countI == 2) {
                printf("%c%c", 'K', 'A');
                countK++;
                countA++;
            }
        } else {
            printf("%c", current->alphabet);
        }
    }
    printf("\n");

    free(stack);

    return 0;
}