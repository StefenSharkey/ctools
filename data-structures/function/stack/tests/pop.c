#include "common.h"

int main() {
    struct StringStack *stack = string_stack_init();

    string_stack_push(stack, "foo");
    string_stack_push(stack, "bar");
    string_stack_push(stack, "baz");
    string_stack_push(stack, "tuna");
    string_stack_push(stack, "spam");

    assert(ct_stack_is_empty(stack) == 0);
    assert(ct_stack_length(stack) == 5);

    assert(strcmp(string_stack_pop(stack), "spam") == 0);
    assert(stack->length == 4);
    assert(stack->top != NULL);

    assert(strcmp(string_stack_pop(stack), "tuna") == 0);
    assert(stack->length == 3);
    assert(stack->top != NULL);

    assert(strcmp(string_stack_pop(stack), "baz") == 0);
    assert(stack->length == 2);
    assert(stack->top != NULL);

    assert(strcmp(string_stack_pop(stack), "bar") == 0);
    assert(stack->length == 1);
    assert(stack->top != NULL);

    assert(strcmp(string_stack_pop(stack), "foo") == 0);
    assert(stack->length == 0);
    assert(stack->top == NULL);
    
    assert(ct_stack_is_empty(stack) == 1);
    assert(ct_stack_length(stack) == 0);

    string_stack_free(stack);
}
