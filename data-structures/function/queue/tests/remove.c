#include "common.h"

int main() {
    struct StringQueue *queue = string_queue_init();    

    string_queue_enqueue(queue, "foo");
    string_queue_enqueue(queue, "bar");
    string_queue_enqueue(queue, "baz");
    string_queue_enqueue(queue, "tuna");
    string_queue_enqueue(queue, "spam");

    assert(strcmp(string_queue_dequeue(queue), "foo") == 0);
    assert(strcmp(queue->front->value, "bar") == 0);
    assert(queue->front != NULL);
    assert(queue->back != NULL);
    assert(queue->length == 4);

    assert(strcmp(string_queue_dequeue(queue), "bar") == 0);
    assert(strcmp(queue->front->value, "baz") == 0);
    assert(queue->front != NULL);
    assert(queue->back != NULL);
    assert(queue->length == 3);

    assert(strcmp(string_queue_dequeue(queue), "baz") == 0);
    assert(strcmp(queue->front->value, "tuna") == 0);
    assert(queue->front != NULL);
    assert(queue->back != NULL);
    assert(queue->length == 2);

    assert(strcmp(string_queue_dequeue(queue), "tuna") == 0);
    assert(strcmp(queue->front->value, "spam") == 0);
    assert(queue->front != NULL);
    assert(queue->back != NULL);
    assert(queue->length == 1);

    assert(strcmp(string_queue_dequeue(queue), "spam") == 0);
    assert(queue->front == NULL);
    assert(queue->back == NULL);
    assert(queue->length == 0);


    string_queue_free(queue);
}
