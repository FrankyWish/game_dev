#include <stdio.h>

#define MAX_SIZE 100 // Assuming maximum number of people in line

void print_line(int arrangement[], int n) {
    int line[MAX_SIZE] = {0}; // Array to store the order of people's numbers in the line

    for (int i = 0; i < n; i++) {
        if (arrangement[i] == -1) {
            line[0] = i + 1; // Person i is at the front of the line
        } else {
            line[arrangement[i]] = i + 1;
        }
    }

    printf("People's numbers in the line from front to back: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", line[i]);
    }
    printf("\n");
}

int main() {
    int arrangement[] = {-1, 2, 1, 3, -1};
    int n = sizeof(arrangement) / sizeof(arrangement[0]);
    print_line(arrangement, n);
    return 0;
}
