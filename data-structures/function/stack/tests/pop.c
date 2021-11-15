#include "common.h"

int main() {
    struct StringStack *stack = string_stack_init();

    string_stack_push(stack, "foo");
    string_stack_push(stack, "bar");
    string_stack_push(stack, "baz");
    string_stack_push(stack, "tuna");
    string_stack_push(stack, "spam");

    string_stack_free(stack);
}
