---
title: Programming C in a UNIX Environment – Review
author: [Connor Baker]
date: Compiled on \today\ at \currenttime
subject: August 28, 2019 Lecture of CS 367
keywords: [GMU, Fall, 2019, CS, 367]
subtitle: GMU Fall 2019 CS 367
logo: images/GMU-CS-BLUE.png
logo-width: 273 # Size at which the logo is centered
lang: en
titlepage: true
titlepage-color: FFFFFF
titlepage-text-color: 0d47a1
titlepage-rule-color: 0d47a1
titlepage-rule-height: 2
papersize: letter
fontsize: 10pt
listings-disable-line-numbers: false
table-use-row-colors: true
footer-right: \thepage\ of \pageref{LastPage}
header-right: \today
header-includes:
 - \setcounter{page}{0} # So that the titlepage is the zeroth page
 - \usepackage{datetime}
 - \settimeformat{ampmtime}
 - \usepackage{lastpage}
---

## Reading Track

Reading homework:

1. Read through Chapter 2.1 (bits and information storage) of the textbook
   + The next lecture begins with bitwise, logical, and shift operations in C
2. Continue to review C. If you know these well in C, it will be a lot easier over the next two months.
   + Passing by reference and working with pointers in functions
   + Dereferencing values: `*ptr = 42;`
   + Pointer arithmetic with arrays: `*(ary + 3) = 42;`
   + Working with `struct`s and dynamic memory
   + Working with linked lists using dynamically allocated `struct`s

## Lecutre Overview from CS262

![Lecture overview.](images/CReview.png){ width=100% }

## Programming Tools in UNIX

+ Integrated Development Environments (IDE)
  + Visual Studio, Netbeans, Eclipse, jGRASP
  + These don't work (or work well) over a remote terminal
    + In Systems Programming, it's common to remotely connect to an embedded device and work directly on it
    + This semester, we'll be working on the Zeus server remotely
+ You don't need an IDE. All you need are
  + A text editor (`vi`/`vim` or `emacs`)
  + A compiler (`gcc`)
  + A debugger (`gdb`)

## Compiling on Zeus

The general template we'll be using is

```bash
gcc -g -01 -o executable source_file.c
```

The flags used in this example are

+ `-g` Compile with symbols in the code. Useful for debugging.
+ `-O1` Compile with optimization level one. This reduces the code/memory footprint.
+ `-o` Specify the output filename. If you don't specify the output, you'll get `a.out`.

## Makefiles

Makefiles are super useful for building multi-source file programs.

There are three parts to each *rule* in a Makefile. Let's diagram walk through the following rule.

```Makefile
prog: prog.c lib.c
    gcc –g –o prog prog.c lib.c
```

Component | Example |
:-------: | :-----: |
Rule name | `prog` |
Dependencies | `prog.c lib.c` |
Action | `gcc -g -o prog prog.c lib.c` |

The Makefile ensures that the dependencies have been satisfied before running the action. If you were to put another rule as a dependency, it would verify that *that* dependency was satisfied before continuing.

Note that the tab before the action is important!

## Pointers

At the machine level, you get two types of data: *values* and *addresses*.

C pointers let us work with addresses.

Before we continue, let's look at the size of different data types on Zeus.

Data Type | Size |
:-------: | :--: |
`char` | 1 B |
`short` | 2 B |
`int` | 4 B |
`long` | 8 B |
`char *` | 8 B |
`short *` | 8 B |
`int *` | 8 B |
`long *` | 8 B |

### Example 1

Consider the following example:

```c
int main() {
  int a = 42;
  int *p;
}
```

1. How do we set `p` to point to `a`?
   + Let `p` reference the memory address of `a`: `p = &a;`
2. How do we set `a` to 12 using `p`?
   + Dereference `p` to change it's value: `*p = 12;`

### Question 1

*File*: `ptr_2.c`

What will the output of the following program be?

```c
#include <stdio.h>

int main() {
  int a = 42, b = 16;
  int *p, *q;
  p = &a;
  q = &b;
  *q = *p;
  p = q;
  printf("%d %d %d %d\n", a, b, *p, *q);
}
```

The output is:

```bash
$ ./ptr_2
42 42 42 42
```

The pointee of `q` is set equal to the pointee of `p` with the statement `*q = *p;`. The statement `p = q;` changes `p` so that it points at the same thing that `q` does -- a value which was set equal the thing that `p` *was* pointing at earlier.

### Question 2

Write a function called swap to exchange two integers by reference.

```c
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
```

## Arrays

An array is a list of values arranged consecutively in memory.

Arrays in C use the `[]` bracket notation which is indexed by offsets. In fact, `a[n]` is really just syntactic sugar for `*(a + n)`. Remember that pointers are a different type: when you add an integer to a pointer, it's scaled by something akin to the `sizeof` function.

Some examples:

+ `int a[5];` declares an array of five `int`s (on Zeus this is 20 bytes)
+ `a[0]` references the value at address `a`
+ `a[1]` references the value at the address `(a+1)`.
  + As noted above, in hardware this would be the address of `a` plus four bytes (since an `int` on Zeus is four bytes)
+ `a[4]` references the last element of `a`
+ `a[5]` is out of bounds but completely legal C -- no bounds checking, remember?

## Arrays and Pointers

*Files*: `ary_a.c` and `ary_b.c`.

The name of the array is the address at of the start of the array. An array name is *not* a variable -- it is a constant value.

This may be surprising. "But an array name is an `lvalue`!" you might claim -- and you'd be correct. However, an array name is not a *modifiable* `lvaule`. For an excellent breakdown, see this Stack Overflow post:

[Is there a reason why an array name is not an lvalue?](https://stackoverflow.com/questions/39021998/is-there-a-reason-why-an-array-name-is-not-an-lvalue)

## Pointer Arithmetic in Arrays

*File*: `ptr_ary.c`.

You can use pointer arithmetic when working with arrays.

```c
int nums[5] = {1, 6, 10, 42, -14};
int *p_nums = NULL;
p_nums = nums;
// Address of the array
printf("Address of nums: %p\n", nums);
printf("Address p_nums points to: %p\n", p_nums);
// Access the fourth number with [] notation
printf("p_nums[3] == %d\n", p_nums[3]);
// Access the fourth number with pointer arithmetic
printf("p_nums[3] == %d\n", *(p_nums + 3));
```

### Question 3

Given the following snippet:

```c
int nums[5] = {1, 6, 10, 42, -14};
int *p_nums = &nums[3];
p_nums = nums;
// Address of nums = 0x400
// sizeof(int) = 4 bytes, sizeof(int *) = 8 bytes
```

what is the value of each of the following expressions?

1. `&nums[2]`
   + 0x408
2. `p_nums[-1]`
   + 10
3. `*(p_nums + 1)`
   + -14

## I/O in C

What is `stdio.h`?

+ The header file for the C Standard Library (`libc.a`)

Okay, so what's `libc.a`?

+ A static library which is automatically included
+ It's a set of pre-compiled C objects which contain all of the core C functions
+ `stdio.h` only has the prototypes and macros for those functions

Some examples of standard I/O operations:

+ Opening and closing files: `fopen` and `fclose`
+ Reading and writing files: `fread` and `fwrite`
+ Reading and writing text: `fgets` and `fputs`
+ Formatted reading and writing: `fscanf` and `fprintf`

Standard I/O is implemented on top of the Operating System (OS) I/O:

![Unix I/O interacting with C I/O.](images/IODiagram.png){ width=50% }

## Standard I/O Streams in C and Unix

Standard I/O models all open files as streams. This is an abstraction for a file descriptor and a buffer.

There are three streams all C programs start with access to:

Name | Type | Buffered? | File Descriptor |
:-: | :-: | :-: | :-: |
`stdin` | Standard Input | yes | 0 |
`stdout` | Standard Output | yes | 1 |
`stderr` | Standard Error | no | 2 |

## Common I/O Functions

These are all declared within the `stdio.h` header.

Function | Description |
:------: | :---------: |
`putchar` | Displays an ASCII character to the screen |
`getchar` | Reads an ASCII character from the keyboard |
`printf` | Displays a formatted string |
`scanf` | Reads a formatted string |
`fopen` | Open or create a file for I/O |
`fprintf` | Writes a formatted string to a file |
`fscanf` | Reads a formatted string from a file |

## Formatted I/O

Both `printf` and `scanf` allow conversion between ASCII representations and internal data types.

The format string of these functions contains text to be read/written as well as the format characters which describe their formatting.

Code | Description |
:--: | :---------: |
`%d` | Signed decimal integer |
`%f` | Signed decimal floating-point number |
`%x` | Hexadecimal number |
`%e` | Scientific notation |
`%c` | ASCII character |
`%s` | ASCII string |
`%p` | Memory address (hex) |

Both `printf` and `scanf` allow special characters as well.

Code | Description |
:--: | :---------: |
`\n` | Newline |
`\t` | Tab |
`\b` | Backspace |
`\\` | Backslash |
`\'` | Single quote |
`\"` | Double quote |
`\0nnn` | ASCII code $nnn$ in octal |
`\xnnn` | ASCII code $nnn$ in hex |

## printf

*File*: `print.c`.

Prints its first argument (the format string) to `stdout` with all of the formatting characters replaced by the ASCII representation of the corresponding arguments.

As an example, the snippet

```c
int a = 100;
char c = 'z';
char hw[13] = "Hello World!";
double pi = 3.14159;
printf("a: %d, \'%c\', 0x%x\n", a, a, a);
printf("c: %d, '%c', 0x%x\n", c, c, c); printf("hw: \"%s\"\n", hw);
printf("pi: %lf, %.2lf, %e\n", pi, pi, pi);
```

prints

```bash
$ ./print
a: 100, 'd', 0x64
c: 122, 'z', 0x7a
hw: "Hello World!"
pi: 3.141590, 3.14, 3.141590e+00
```

when executed.
