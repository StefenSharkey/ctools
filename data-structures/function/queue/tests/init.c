#include "common.h"

int main() {
    struct StringQueue *queue = string_queue_init();    

    assert(queue->front == NULL);
    assert(queue->back == NULL);
    assert(ct_queue_length(queue) == 0);
    assert(ct_queue_is_empty(queue) == 1);
    assert(queue->length == 0);

    string_queue_free(queue);
}
