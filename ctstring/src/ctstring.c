#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ctstring.h"

/* Utility */
size_t ctstring_next_size(struct CtString* string) {
    return string->capacity + 7;
}

size_t ctstring_length(struct CtString* string) {
    return string->length;
}

void ctstring_print(struct CtString* string) {
    size_t index;

    for(index = 0; index < string->length; index++) {
        printf("%c", string->string[index]);
    }

    printf("%c", '\n');
}

int ctstring_compare(struct CtString* compare_a, struct CtString* compare_b) {
    size_t index;

    /* Can only compare strings of equal length */
    if(compare_a->length != compare_b->length) {
        return 0;
    }

    for(index = 0; index < compare_a->length; index++) {
        if(compare_a->string[index] == compare_b->string[index]) {
            continue;
        }

        return 0;
    }

    return 1;
}

int ctstring_compare_nt(struct CtString* compare_a, const char* compare_b) {
    size_t index;
    size_t string_length = strlen(compare_b);

    /* Can only compare strings of equal length */
    if(compare_a->length != string_length) {
        return 0;
    }

    for(index = 0; index < compare_a->length; index++) {
        if(compare_a->string[index] == compare_b[index]) {
            continue;
        }

        return 0;
    }

    return 1;
}

/* Major memory related */
struct CtString* ctstring_init(size_t capacity) {
    struct CtString* new_string = calloc(1, sizeof(struct CtString));

    new_string->capacity = capacity;
    new_string->string = calloc(capacity, sizeof(char));

    return new_string;
}

/*
struct CtString* ctstring_initf(size_t capacity, const char*) {
    struct CtString* new_string = calloc(1, sizeof(struct CtString));

    new_string->capacity = capacity;
    new_string->string = calloc(capacity, sizeof(char));

    return new_string;
}
*/

void ctstring_free(struct CtString* string) {
    free(string->string);
    free(string);
}

/* Concatenation / Addition */
struct CtString* ctstring_concat(struct CtString* dest, const struct CtString* src) {
    size_t index;

    /* Resize the destination if the capacity cannot fit the current buffer */
    if(dest->length + src->length > dest->capacity) {
        dest->capacity = src->length + ctstring_next_size(dest);
        dest->string = realloc(dest->string, sizeof(char) * dest->capacity);
    }

    /* Append SRC's characters to DEST */
    for(index = 0; index < src->length; index++) {
        dest->string[dest->length + index] = src->string[index];
    }

    dest->length = dest->length + src->length;

    return dest;
}

struct CtString* ctstring_concat_nt(struct CtString* dest, const char* src) {
    size_t index;
    size_t src_length = strlen(src);

    /* Resize the destination if the capacity cannot fit the current buffer */
    if(dest->length + src_length > dest->capacity) {
        dest->capacity = dest->length + src_length + ctstring_next_size(dest);
        dest->string = realloc(dest->string, sizeof(char) * dest->capacity);
    }

    /* Append SRC's characters to DEST */
    for(index = 0; index < src_length; index++) {
        dest->string[dest->length + index] = src[index];
    }

    dest->length = dest->length + src_length;

    return dest;
}

struct CtString* ctstring_concat_ch(struct CtString* dest, const char character) {
    /* Resize the destination if the capacity cannot fit the current buffer */
    if(dest->length + 1 > dest->capacity) {
        dest->capacity = 1 + ctstring_next_size(dest);
        dest->string = realloc(dest->string, sizeof(char) * dest->capacity);
    }

    /* Append character to DEST */
    dest->string[dest->length] = character;
    dest->length = dest->length + 1;

    return dest;
}

struct CtString* ctstring_repeat(struct CtString* string, unsigned int repeat) {
    size_t original_range = string->length;

    /* Resize the string to fit the new copies if needed */
    if(original_range * repeat > string->capacity) {
        string->capacity = ctstring_next_size(string) * repeat;
        string->string = realloc(string->string, sizeof(char) * string->capacity);
    }

    /* Append STRING to itself REPEAT -1 times. (This is to replicate Python's behavior) */
    while(repeat != 1) {
        size_t index;

        for(index = 0; index < original_range; index++) {
            string->string[string->length + index] = string->string[index];
        }

        string->length = string->length + original_range;
        repeat = repeat - 1;
    }

    return string;
}

/* Stripping, snipping, subtraction */
int ctstring_split(struct CtString* string, struct CtString* buffer, size_t* start, char delim) {
    size_t index;
    struct CtString split;

    split.length = 0;
    split.capacity = string->capacity;
    split.string = string->string + (*start);

    /* Signal the end of the split sequence, and set the start index back to 0 */
    if(*start >= string->length) {
        (*start) = 0;
        (*buffer) = split;

        return 1;
    }

    /* Probe forward until the delimiter is found */
    for(index = *start; index < string->length; index++) {
        if(string->string[index] != delim) {
            continue;
        }

        break;
    }

    split.length = index - (*start);
    (*start) = index + 1;
    (*buffer) = split;

    return 0;
}

struct CtString ctstring_slice(struct CtString* string, size_t start, size_t stop) {
    struct CtString slice;

    slice.length = stop - start;
    slice.capacity = string->capacity;
    slice.string = string->string + start;

    return slice;
}

struct CtString* ctstring_set(struct CtString* string, char byte) {
    size_t index;

    for(index = 0; index < string->length; index++) {
        string->string[index] = byte;
    }

    return string;
}

struct CtString* ctstring_cut(struct CtString* string, size_t start, size_t stop) {
    size_t cursor = start;
    size_t stop_index;

    for(stop_index = stop; stop_index < string->length; stop_index++) {
        string->string[cursor] = string->string[stop_index];
        cursor++;
    }

    string->length -= (stop - start);

    return string;
}

int ctstring_find(struct CtString* string, struct CtString* find) {
    size_t index;

    /* Find is too large */
    if(find->length > string->length) {
        return -1;
    }

    for(index = 0; index < string->length - (find->length - 1); index++) {
        struct CtString snippet = ctstring_slice(string, index, index + find->length);

        if(ctstring_compare(find, &snippet) == 0) {
            continue;
        }

        return (int) index;
    }

    return -1;
}

/* Transformation */
size_t ctstring_to_nt(struct CtString* string, char buffer[], size_t length) {
    size_t cursor = 0;

    for(cursor = 0; cursor < string->length; cursor++) {
        if(cursor >= length) {
            break;
        }

        buffer[cursor] = string->string[cursor];
    }

    buffer[cursor] = '\0';
    
    return cursor;
}

struct CtString* ctstring_nt_to_ctstring(char string[]) {
    struct CtString* new_string = ctstring_init(strlen(string));
    ctstring_concat_nt(new_string, string);

    return new_string;
}

struct CtString* ctstring_lower(struct CtString* string) {
    size_t index;

    for(index = 0; index < string->length; index++) {
        char character = string->string[index];

        /* Ignore lowercase and or non-alphabetical characters */
        if(character < 'A' || character > 'Z') {
            continue;
        }

        string->string[index] = character + 32;
    }

    return string;
}

struct CtString* ctstring_upper(struct CtString* string) {
    size_t index;

    for(index = 0; index < string->length; index++) {
        char character = string->string[index];

        /* Ignore lowercase and or non-alphabetical characters */
        if(character < 'a' || character > 'z') {
            continue;
        }

        string->string[index] = character - 32;
    }

    return string;
}

/* File functions */
struct CtString* ctstring_delim(FILE* stream, char delim) {
    struct CtString* new_string = ctstring_init(32);
    char character = (char) fgetc(stream);

    while(character != EOF) {
        ctstring_concat_ch(new_string, character);

        /* End of the line */
        if(character == delim) {
            break;
        }

        character = (char) fgetc(stream);
    }

    return new_string;
}

struct CtString* ctstring_delim_buffer(struct CtString* buffer, FILE* stream, char delim) {
    char character = (char) fgetc(stream);
    buffer->length = 0;

    while(character != EOF) {
        ctstring_concat_ch(buffer, character);

        /* End of the line */
        if(character == delim) {
            break;
        }

        character = (char) fgetc(stream);
    }

    return buffer;
}
