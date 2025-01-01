#include <stdio.h>
#include <string.h>

int main() {
    int t = 9; // Number of test cases
    while (t--) {
        char arr[100]; // Array to store the input string
        int length;

        printf("Enter the string: ");
        scanf("%s", arr); // Read the string

        length = strlen(arr); // Get the length of the string

        // Check if the string is invalid
        if (length < 2 || arr[length - 1] != 'b' || arr[length - 2] != 'b') {
            printf("Given string is invalid\n");
        } else {
            // Check if the string has valid characters before "bb"
            int valid = 1; // Assume valid unless proven otherwise
            for (int i = 0; i < length - 2; i++) {
                if (arr[i] != 'a') {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                printf("Given string is valid\n");
            } else {
                printf("Given string is invalid\n");
            }
        }
    }

    return 0;
}
