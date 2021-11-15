#include "common.h"

int main() {
    struct StringStack *stack = string_stack_init();

    assert(stack->length == 0);
    assert(ct_stack_length(stack) == 0);
    assert(ct_stack_is_empty(stack) == 1);
    assert(stack->top == NULL);

    string_stack_free(stack);
}
