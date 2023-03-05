#pragma once

#include <stddef.h>

extern void *term_alloc(size_t size);
extern void *term_realloc(void *oldptr, size_t size);
extern void term_free(void *ptr, size_t size);
extern void term_freensz(void *ptr);

extern void *term_memcpy(void *dest, const void *src, size_t size);
extern void *term_memset(void *dest, int val, size_t count);