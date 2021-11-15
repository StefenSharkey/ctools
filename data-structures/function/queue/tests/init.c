#include "common.h"

int main() {
    struct StringQueue *queue = string_queue_init();    

    assert(queue->front == NULL);
    assert(queue->back == NULL);
    assert(queue->length == 0);

    string_queue_free(queue);
}
