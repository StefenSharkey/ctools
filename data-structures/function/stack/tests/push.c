#include "common.h"

int main() {
    struct StringStack *stack = string_stack_init();

    string_stack_push(stack, "foo");
    assert(stack->length == 1);
    assert(strcmp(stack->top->value, "foo") == 0);
    assert(stack->top->next == NULL);

    string_stack_push(stack, "bar");
    assert(stack->length == 2);
    assert(strcmp(stack->top->value, "bar") == 0);
    assert(strcmp(stack->top->next->value, "foo") == 0);

    string_stack_push(stack, "tuna");
    assert(stack->length == 3);
    assert(strcmp(stack->top->value, "tuna") == 0);
    assert(strcmp(stack->top->next->value, "bar") == 0);
    assert(strcmp(stack->top->next->next->value, "foo") == 0);

    string_stack_free(stack);
}
