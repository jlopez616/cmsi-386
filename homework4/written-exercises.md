# John Lopez and Anthony Boyac Written Exercises
## Problem 1
On my machine, the address for `A[0][0]` was 0x407040.
On my machine, the address for `A[3][7]` was 0x407168.

Although integers take up 4 bytes of memory, and characters take up 1 byte of memory, A as a type took up 8 bytes of memory. So row 3, column 7, would be 296 bytes away from the start of the array, and would explain the address difference of 128 hex.

## Problem 2
Line 1 declares a as an array of n integer pointers, so each element
in a holds a pointer to a double value.

Line 2 declares b as a pointer to
an array of n integers.

Line 3 declares c[n] as a pointer to a function.

Line 4 declares the function d() as a pointer to the array [n].

## Problem 3
F is a pointer to a function that accepts a function
and a double and returns a function that accepts a
pointer to a function and a function that accepts
a double and a double array that returns a double and
accepts a double that returns a double.

## Problem 4
The Derived object contains two b field. Derived inherits string b from the base class,
and it creates a new b field of type int. In this format, we would get a compilator error
since b is ambiguous. If we want to access both of them, we would have to use the right
scope, like this:
    d.Base::b = "blahblah";

## Problem 5
The program outputs a 2, a 5, and a 2. This makes sense because the binding is determined by innermost declaration, searching outward if needed.
The only variable declared inside of a function would be inside of g(). So when g() is asked to write to standard output, it searches and successfully identifies the declaration of x=5. However, when both f() and main() are asked to write to standard output, the compiler searches outside of the functions for a declaration and identifies the declaration of x=2.

If C++ were a dynamically scoped language, the output would be 5, 5, and 2, because dynamic scope binding is determined by the one most recently encountered during execution. Variables are added to a call stack. So when the program first runs, it sees that x=2, and puts that at the bottom of the call stack for the main program's frame. Then, it runs main, which first asks to run g(). As g() is executed, 5 is added to its frame the call stack, so when f() runs, 5 is also added to its frame. Since f() is the first to print, it prints its frame (5). Then, g's frame (5), then the main program's frame (2).

## Problem 6
The signatures would be `template <typename T>
void shuffle(T* arr, int length);` for a raw array, and
`void coolerShuffle(std::array<template <typename T>, length> betterArr)` for a standard array.
