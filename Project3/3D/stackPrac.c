#include <stdio.h>
#include <stdlib.h>

#define STACK_CAPACITY 100

typedef struct {
    int top;
    int array[STACK_CAPACITY];
} Stack;

Stack* createStack(){
    Stack *s = malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

void push(Stack *stack, int object){
    int num = stack->top;
    if (num >= STACK_CAPACITY -1)
    {
        printf("Stack is full\n");
        
    }
    else{
    stack->top++;
    stack->array[stack->top] = object;   
    }
}

int pop(Stack *stack){
    if (stack->top >= STACK_CAPACITY -1){
        printf("Stack is full\n");
    }
    else{
    int object = stack->array[stack->top];
    stack->top--;
    return object;
    }

}




int main() {
    Stack *stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    int x = pop(stack);
    int y = pop(stack);
    int z = pop(stack);
    printf("Is popped, %d\n", x);
    printf("Is popped, %d\n", y);
    printf("Is popped, %d\n", z);



}