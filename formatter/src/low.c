#include <stdio.h>
#include "convert.h"

int main() {
    char input[100];
    
    printf("Enter text: ");
    fgets(input, 100, stdin);
    
    to_lower(input);
    printf("Lowercase: %s", input);
    
    return 0;
}
