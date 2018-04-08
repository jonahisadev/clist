# CLIST

A resizable list macro for C

## About

Below is why I made this, how to use it, and how you can
contribute.

### What Is This?

A big reason I use C++ is for templates, specifically
because I can use templates to easily create list classes
capable of growing dynamically. I dread starting projects
in C because I know I have to program those list structures
by hand for every type that I'd like.

Not anymore.

I created a macro that allows me to easily create list
structures without having to code each list type by hand by
using a generic structure and the C preprocessor.

### How to Use (Quick Start)

Go ahead and download `clist.h` and put that somewhere that
you can include in your project.

```c
#include "clist.h"
```

Call the `CLIST` macro to create the structure and functions
that go along with it. Below is an example of creating an
integer list.

```c
CLIST(int, IntList)
```

`int` is the type that the list will use and `IntList` is the
name of the structure to be created, along with the helper
functions.

Below is an example of how one might use a list from the one
created above.

```c
#include "clist.h"

CLIST(int, IntList)

int main() {
	IntList* list = IntList_new(1);
	IntList_add(list, 42);
	int foo = IntList_get(list, 0);
	IntList_delete(list);
	return foo;
}
```

The above program should return `42`. The helper functions are
documented below if you would like to know more of what they
do. Following the above example should work for most, if not
all implementations of lists.

### Helper Functions

`T` is the list type

`X` is the list name

#### new

```c
X* X_new(int size);
```

This creates a new list with `size * sizeof(T)` amount of
memory. You can fit `size` amount of elements in the list
before it resizes itself.

#### add

```c
void X_add(X* self, T data);
```

This adds an element to the list, and also resizes it if
necessary. If the list needs to resize, the new max is
double the last. For example, if your initial size is
`5` then `5 * 2 == 10`, which is the new size.

#### get

```c
T X_get(X* self, int index);
```

This simply returns data from a specified index, similar
to that of a standard array.

#### delete

```c
void X_delete(X* self);
```

This deletes the data within the list, and then deletes
the list itself. It is recommended that this is called
before exiting the program.

### How to Contribute

As of now, I'm just going to leave the macro as it is.
If you happen upon some bugs, you can either submit an
issue for me to fix, or you can fix it yourself and submit
a pull request.

You can email me at [jonahisadev@gmail.com](mailto:jonahisadev@gmail.com)
if you'd like to chat about bugs, the macro, or general things.