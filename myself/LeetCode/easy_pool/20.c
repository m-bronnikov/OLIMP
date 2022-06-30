#include <stdio.h>
#include <stdbool.h>

#include <stdlib.h>

bool is_open(char c)
{
    switch (c)
    {
    case '(':
        return true;
    case '[':
        return true;
    case '{':
        return true;
    default:
        break;
    }

    return false;
}

bool is_right_closing(char open, char close)
{
    if(open == '(')
        return close == ')';
    if(open == '[')
        return close == ']';

    return close == '}';
}

typedef struct Stack Stack;
struct Stack{
    char* data;
    int size;

    void (*add)(Stack*, char);
    char (*pop)(Stack*);
};

void add_to_stack(Stack* stack, char c)
{
    stack->data[stack->size++] = c;
}

char pop_from_stack(Stack* stack)
{
    return stack->data[--stack->size];
}

Stack allocate_stack(int capacity)
{
    Stack stack;
    stack.data = (char*)malloc(capacity * sizeof(char));
    stack.size = 0;
    stack.add = &add_to_stack;
    stack.pop = &pop_from_stack;
    return stack;
}

void free_stack(Stack* stack)
{
    free(stack->data);
    stack->data = NULL;
    stack->size = 0;
}


bool isValid(const char* s){
    // define size
    int size = 0;
    while(s[size] != '\0') ++size;

    // string with odd size is wrong sequence
    if(size & 1) return false;

    Stack stack = allocate_stack(size);
    bool result = true;

    while(*s != '\0')
    {
        if(is_open(*s))
        {
            stack.add(&stack, *s);
            ++s;
            continue;
        }

        if(stack.size == 0 || !is_right_closing(stack.pop(&stack), *s))
        {
            result = false;
            break;
        }

        ++s;
    }

    result = result && stack.size == 0;

    free_stack(&stack);
    return result;
}


int main()
{
    printf("%d\n", isValid("()"));
    return 0;
}