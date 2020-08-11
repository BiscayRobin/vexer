#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <uchar.h>

#define VECTOR_INIT_CAPACITY 4

typedef struct vector {
    void **items;
    size_t capacity;
    size_t total;
} vector;

vector *vector_new();
void vector_delete(vector *v);
void vector_display(vector *v, void (*display_func)(void *));
void vector_push(vector *v, void *item);
void *vector_pop(vector *v);
void *vector_front(vector *v);
void *vector_back(vector *v);
void *vector_at(vector *v, size_t index);
bool vector_empty(vector *v);
size_t vector_size(vector *v);
size_t vector_capacity(vector *v);
size_t vector_maxSize(vector *v);
void vector_insert(vector *v, size_t index, void *item);
void vector_clear(vector *v);
void vector_shrinkToFit(vector *v);
void vector_reserve(vector *v, size_t size);
void vector_resize(vector *v, size_t size);

#endif
