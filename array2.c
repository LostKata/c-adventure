#include <stdio.h> // Header

short b = 42; // short byte
int a = 42; // integer, contains only whole numbers
float f = 3.14; // float, contains numbers with decimals
double d = 3.1415; // double data type contains up to 15 decimals
int fib[6] = {0,1,1,2,3,5}; // array and in fib[6] means that the array size will be 6

int main() {
    for (int i=0; i<6; i++) {
        printf("fib[%d]=%d @ %p\n", i, fib[i], &fib[i]);
    }
    return 0; // this line ends the code
}


/* Data types
printf("sizeof(a): %lu\n", sizeof(a)); // %lu declaration for data type, sizeof(a) finds the memory storage size in the ram.
printf("address of a: %p\n", &a); // &a = address of , Returns the memory address of argument
    
printf("sizeof(f): %lu\n", sizeof(f)); 
printf("address of f: %p\n", &f); 

printf("sizeof(d): %lu\n", sizeof(d));
printf("address of d: %p\n", &d); 
    
printf("sizeof(b): %lu\n", sizeof(b)); 
printf("address of b: %p\n", &b); */