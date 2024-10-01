#include <stdio.h>
#include "calc.h"


int get_input(void) {
    int a;

    if (scanf("%u", &a) != 1) {
        fprintf(stderr, "Invalid input! Please enter a number.\n");
        return (-1);
    }
    return a;
}

int main() {
    int choice;
    int a, b;
    
    printf("Welcome to the Calculator!\n");
    printf("Choose an operation:\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Factorial\n6. Square Root\n");
    printf("Enter your choice: ");
    choice = get_input();
    if (choice < 0) return (-1); 

    switch (choice) {
        case 1:  // Add
	case 2:  // Subtract
	case 3:  // Multiply
	case 4:  // Divide
            printf("Enter two numbers: \n");
	    a = get_input();
            b = get_input();
	    if ((a < 0) || (b < 0)) return (-1);

	    switch (choice) {
	      	case 1:  // Add
            		printf("Result: %.2f\n", add(a, b));
            		return 0;
        	case 2:  // Subtract
            		printf("Result: %.2f\n", subtract(a, b));
            		return 0;
        	case 3:  // Multiply
            		printf("Result: %.2f\n", multiply(a, b));
            		return 0;
        	case 4:  // Divide
            		printf("Result: %.2f\n", divide(a, b));
            		return 0;
	     }
        case 5:  // Factorial
	case 6:  // Square Root
            printf("Enter a number: \n");
	    a = get_input();
            if (a < 0) return (-1); 
	    switch (choice) {
		case 5:  // Factorial
            		printf("Result: %llu\n", factorial(a));
            		return 0;
        	case 6:  // Square Root
            		printf("Result: %.2f\n", square_root(a));
            		return 0;
	    }
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
