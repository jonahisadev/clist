/*
		CLIST.H

		Copyright (c) 2018 Jonah Alligood
*/

#include <stdlib.h>

#define CLIST(T, name) \
typedef struct _##name { \
	T* data; \
	int size; \
	int ptr; \
} name; \
name* name##_new(int size) { \
	name* self = (name*) malloc(sizeof(name)); \
	self->data = (T*) malloc(sizeof(T) * size); \
	self->size = size; \
	self->ptr = 0; \
	return self; \
} \
T name##_get(name* self, int index) { \
	return self->data[index]; \
} \
void name##_add(name* self, T data) { \
	if (self->ptr >= self->size) { \
		self->size *= 2; \
		self->data = (T*) realloc(self->data, self->size); \
	} \
	self->data[self->ptr] = data; \
} \
void name##_delete(name* self) { \
	free(self->data); \
	free(self); \
}