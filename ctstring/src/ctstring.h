/*
 * ctString is a string library for C. The strings are implemented on the heap, and are
 * implemented as Pascal-style strings.
*/

#ifndef CT_STRING_H
#define CT_STRING_H

#include <stdio.h>
#include <stdlib.h>

#define CT_STRING_FGETS_BUFFER 256

/*
 * The base string object for ctString. Contains the length of
 * the string, as well as the block of memory allocated for it.
*/
struct CtString {
    size_t length;
    size_t capacity;
    char* string;
};

/*
 * Returns the length of the string. Constant time operation.
 *
 * @param string: the string to retrieve the length of
 * @return: the length of the string
*/
size_t ctstring_length(struct CtString* string);

/*
 * Prints a ctString STRING to the stdout.
 *
 * @param string: the string to print
*/
void ctstring_print(struct CtString* string);

/*
 * Initialize a new string on the heap.
 *
 * @param capacity: the initial capacity of the string
 * @return: a new string
*/
struct CtString* ctstring_init(size_t capacity);

/*
 * Releases a string from memory.
 *
 * @param string: the string to release
*/
void ctstring_free(struct CtString* string);

/*
 * Concatenates a SRC string onto the DEST string.
 *
 * @param dest: the string to concatenate to
 * @param src: the string to concatenate
 * @return: the DEST string
*/
struct CtString* ctstring_concat(struct CtString* dest, const struct CtString* src);

/*
 * Concatenates a NULL-terminated string SRC onto the DEST string.
 *
 * @param dest: the string to concatenate to
 * @param src: the string to concatenate
 * @return: the DEST string
*/
struct CtString* ctstring_concat_nt(struct CtString* dest, const char* src);

/*
 * Concatenate a single character without the overhead of a for loop.
 *
 * @param dest: the stringto concatenate to
 * @param character: the character to concatenate
 * @return: the string concatenated to
*/
struct CtString* ctstring_concat_ch(struct CtString* dest, const char character);

/*
 * Adds STRING to itself REPEAT times.
 *
 * @param string: the string to repeat
 * @param repeat: the number of times to repeat
 * @return: the repeated string
*/
struct CtString* ctstring_repeat(struct CtString* string, unsigned int repeat);

/*
 * 'Splits' the string STRING at the next delimiter DELIM,
 * starting at an index START. Returns a status code which
 * tells the programmer if the split has finished or not.
 * Each time, the split data is written to the buffer of choice.
 *
 * @param string: the string to split
 * @param buffer: the location to store the split buffer in
 * @param start: the index to start at
 * @param delim: the character to split at
 * @return: 0 if the split is not finished, 1 if it is
*/
int ctstring_split(struct CtString* string, struct CtString* buffer, size_t* start, char delim);

/*
 * Returns the characters between two indexes, START, and STOP, in a new
 * ctString. The string is on the stack, and so does not need to be freed.
 *
 * @param string: the string to slice
 * @param start: start: the index to start at
 * @param stop: the index to stop at
 * @return: a ctString with its string being inside the start and stop points
*/
struct CtString ctstring_slice(struct CtString* string, size_t start, size_t stop);

/*
 * Set the entire string to a certain character.
 *
 * @param string: the string to set the contents of
 * @param byte: the character to use
 * @return: the string that had its bytes assigned
*/
struct CtString* ctstring_set(struct CtString* string, char byte);

/*
 * Cuts a region of a string STRING between indexes START and STOP.
 *
 * @param string: the string to cut from
 * @param start: the index to start cutting from
 * @param stop: the index to stop cutting at
 * @return: the string that the cut was performed on
*/
struct CtString* ctstring_cut(struct CtString* string, size_t start, size_t stop);

/*
 * Compares two strings and returns whether or not they are equal.
 * Keep in mind, this does not replicate the behavior of strcmp from
 * string.h. It *just* checks for equality.
 *
 * @param compare_a: the first string to compare
 * @param compare_b: the second string to compare
 * @return: 0 if they are not equal, and 1 if they are equal
*/
int ctstring_compare(struct CtString* compare_a, struct CtString* compare_b);

/*
 * Compares two a ctString, and NUL-terminated string, and returns
 * whether or not they are equal. Keep in mind, this does not
 * replicate the behavior of strcmp from string.h. It *just*
 * checks for equality.
 *
 * @param compare_a: the first string to compare
 * @param compare_b: the second string to compare
 * @return: 0 if they are not equal, and 1 if they are equal
*/
int ctstring_compare_nt(struct CtString* compare_a, const char* compare_b);

/*
 * Searches for the first occurrence of a ctString FIND inside of
 * a ctString STRING. Returns the index to the start of the string.
 *
 * @param string: the string to search through
 * @param find: the ctString to find
 * @return: the index of the start of the string
*/
int ctstring_find(struct CtString* string, struct CtString* find);

/*
 * Converts a ctString to a C-style NUL-terminated string by writing the
 * characters of a string STRING to a character array BUFFER, which has a
 * length of LENGTH.
 *
 * @param string: the string to convert
 * @param buffer: the location to write the string to
 * @param length: the length of the buffer
 * @return: the number of characters written
*/
size_t ctstring_to_nt(struct CtString* string, char buffer[], size_t length);

/*
 * Converts a NUL-terminated string into a ctString. Semantically
 * equivalent to a call to ctstring_init, and then ctstring_concat_nt.
 *
 * @param string: the NUL-terminated string to convert into a ctString
 * @return: a new ctString on the heap
*/
struct CtString* ctstring_nt_to_ctstring(char string[]);

/*
 * Converts all alphabetical characters into their lowercase form.
 *
 * @param string: the string to convert to lowercase
 * @return: the lower'd string
*/
struct CtString* ctstring_lower(struct CtString* string);

/*
 * Converts all alphabetical characters into their uppercase form.
 *
 * @param string: the string to convert to uppercase
 * @return: the upper'd string
*/
struct CtString* ctstring_upper(struct CtString* string);

/*
 * Retrieves the next delim-terminated string from a file stream
 * STREAM, and returns a new string on the heap that must be freed.
 * The final string contains the delimiter (if there was one).
 *
 * If used inside of a loop, it can be broken once the length of the
 * new string is equal to 0.
 *
 * @param stream: the file stream to read from
 * @return: the new ctString
*/
struct CtString* ctstring_delim(FILE* stream, char delim);

/*
 * Retrieves the next delim-terminated string from a file stream
 * STREAM, and writes it to the CtString buffer. The buffer is reset
 * to length 0 before adding data, which will allow it to be treated
 * like a normal string. This is useful for when repeated calls to
 * malloc-family functions are not desired. The final string contains
 * the delimiter (if there was one).
 *
 * If used inside of a loop, it can be broken once the length of the
 * buffer is equal to 0.
 *
 * @param stream: the file stream to read from
 * @return: the new ctString
*/
struct CtString* ctstring_delim_buffer(struct CtString* buffer, FILE* stream, char delim);

#endif
