#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void *vector_at(vector *v, size_t index) {
    if (index >= 0 && index < v->total) {
        return v->items[index];
    }
    return NULL;
}

void *vector_front(vector *v) { return v->items[0]; }

void *vector_back(vector *v) {
    if (vector_empty(v))
        return NULL;
    return v->items[v->total - 1];
}

void **vector_data(vector *v) { return v->items; }

bool vector_empty(vector *v) { return !v->total; }

size_t vector_size(vector *v) { return v->total; }

size_t vector_maxSize(vector *v) {
    (void)v;
    return SIZE_MAX;
}

void vector_resize(vector *v, size_t size) {
    void **items = realloc(v->items, sizeof(void *) * size);
    if (items) {
        v->items = items;
        v->capacity = size;
    }
}

void vector_reserve(vector *v, size_t size) {
    if (size <= v->capacity)
        return;
    vector_resize(v, size);
}

size_t vector_capacity(vector *v) { return v->capacity; }

void vector_shrinkToFit(vector *v) { vector_resize(v, v->total); }

void vector_clear(vector *v) {
    for (size_t i = 0; i < v->total; i++) {
        v->items[i] = NULL;
    }
    v->total = 0;
}

void vector_push(vector *v, void *item) {
    if (v->total == v->capacity) {
        vector_resize(v, v->capacity * 2);
    }
    v->items[v->total++] = item;
}

void *vector_pop(vector *v) {
    if (vector_empty(v))
        return NULL;
    return v->items[--(v->total)];
}

void vector_insert(vector *v, size_t index, void *item) {
    vector_push(v, vector_back(v));
    for (size_t i = v->total - 1; i >= index; --i) {
        v->items[i] = v->items[i - 1];
    }
    v->items[index] = item;
}

vector *vector_new() {
    vector *v = malloc(sizeof(vector));
    v->capacity = VECTOR_INIT_CAPACITY;
    v->total = 0;
    v->items = malloc(sizeof(void *) * v->capacity);
    return v;
}

void vector_delete(vector *v) { free(v->items); }

void vector_display(vector *v, void (*display_func)(void *)) {
    printf("[");
    if (v->total == 0) {
        printf("]");
        return;
    }
    for (size_t i = 0; i < v->total - 1; i++) {
        if (display_func)
            display_func(v->items[i]);
        else
            printf("%p", v->items[i]);
        printf(", ");
    }
    if (display_func)
        display_func(v->items[v->total - 1]);
    else
        printf("%p", v->items[v->total - 1]);
    printf("]");
}
