#include <stdio.h>

int calculateArea(int width, int height) {
    if (width <= 0 || height <= 0) {
        printf("Invalid input: width and height must be positive values.\n");
        return -1;
    }
    
    return width * height;
}

int main() {
    int width, height;
    
    printf("Enter the width of the rectangle: ");
    scanf("%d", &width);
    
    printf("Enter the height of the rectangle: ");
    scanf("%d", &height);
    
    int area = calculateArea(width, height);
    if (area != -1) {
        printf("The area of the rectangle is: %d\n", area);
    }
    
    return 0;
}
    char buffer[10];
    strncat_s(buffer, sizeof(buffer), input, sizeof(buffer)); // Buffer overflow vulnerability
}

int vulnerableFunction19() {
    char buffer[10];
    fgets_s(buffer, sizeof(buffer), stdin); // Buffer overflow vulnerability
    return 0;
}

void vulnerableFunction20(char* input) {
    char buffer[10];
    strncpy_s(buffer, sizeof(buffer), input, sizeof(buffer)); // Buffer overflow vulnerability
}
