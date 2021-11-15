#include "common.h"

int main() {
    struct StringQueue *queue = string_queue_init();    

    assert(ct_queue_peek(queue) == NULL);
    string_queue_enqueue(queue, "foo");
    assert(queue->length == 1);
    assert(ct_queue_length(queue) == 1);
    assert(queue->front != NULL);
    assert(queue->back != NULL);
    assert(strcmp(queue->front->value, "foo") == 0);
    assert(strcmp(queue->back->value, "foo") == 0);

    assert(strcmp(ct_queue_peek(queue)->value, "foo") == 0);

    string_queue_enqueue(queue, "bar");
    assert(queue->length == 2);
    assert(ct_queue_length(queue) == 2);
    assert(strcmp(queue->front->value, "foo") == 0);
    assert(strcmp(queue->back->value, "bar") == 0);

    string_queue_enqueue(queue, "tuna");
    assert(queue->length == 3);
    assert(ct_queue_length(queue) == 3);
    assert(strcmp(queue->front->value, "foo") == 0);
    assert(strcmp(queue->front->next->value, "bar") == 0);
    assert(strcmp(queue->back->value, "tuna") == 0);

    string_queue_free(queue);
}
