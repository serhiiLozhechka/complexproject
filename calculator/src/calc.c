#include <stdio.h>
#include <math.h>
#include "calc.h"

// Function implementations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

unsigned long long factorial(int n) {
    if (n < 0) {
        printf("Error: Factorial of negative number!\n");
        return 0;
    }
    if (n == 0 || n == 1) return 1;
    
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

double square_root(double a) {
    if (a < 0) {
        printf("Error: Cannot calculate square root of negative number!\n");
        return -1;
    }
    return sqrt(a);
}
