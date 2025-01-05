#include <stdio.h>
#include <string.h>

#define MAX_STATES 100
#define MAX_SYMBOLS 10

// Function to check if the string is accepted by the FA
int isAccepted(const char *str, int numStates, int initialState, int acceptingStates[], int numAcceptingStates, int transitions[MAX_STATES][MAX_SYMBOLS], int numSymbols, char symbols[]) {
    int currentState = initialState;

    for (int i = 0; str[i] != '\0'; i++) {
        char symbol = str[i];
        int symbolIndex = -1;

        // Find the index of the symbol in the input symbols
        for (int j = 0; j < numSymbols; j++) {
            if (symbols[j] == symbol) {
                symbolIndex = j;
                break;
            }
        }

        if (symbolIndex == -1) {
            return 0; // Invalid symbol
        }

        // Transition to the next state
        currentState = transitions[currentState][symbolIndex];
        if (currentState == -1) {
            return 0; // No valid transition
        }
    }

    // Check if the current state is an accepting state
    for (int i = 0; i < numAcceptingStates; i++) {
        if (currentState == acceptingStates[i]) {
            return 1; // Accepted
        }
    }

    return 0; // Rejected
}

int main() {
    int numSymbols, numStates, initialState, numAcceptingStates;
    char symbols[MAX_SYMBOLS];
    int acceptingStates[MAX_STATES];
    int transitions[MAX_STATES][MAX_SYMBOLS];

    // Input FA details
    printf("Enter the number of input symbols: ");
    scanf("%d", &numSymbols);
    printf("Enter the input symbols: ");
    for (int i = 0; i < numSymbols; i++) {
        scanf(" %c", &symbols[i]);
    }

    printf("Enter the number of states: ");
    scanf("%d", &numStates);

    printf("Enter the initial state: ");
    scanf("%d", &initialState);

    printf("Enter the number of accepting states: ");
    scanf("%d", &numAcceptingStates);
    printf("Enter the accepting states: ");
    for (int i = 0; i < numAcceptingStates; i++) {
        scanf("%d", &acceptingStates[i]);
    }

    // Initialize the transition table
    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numSymbols; j++) {
            transitions[i][j] = -1; // Default to no transition
        }
    }

    printf("Enter the transition table (state symbol -> next state):\n");
    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numSymbols; j++) {
            printf("From state %d on symbol %c: ", i, symbols[j]);
            scanf("%d", &transitions[i][j]);
        }
    }

    // Input string to test
    char str[100];
    printf("Enter a binary string: ");
    scanf("%s", str);

    // Check if the string is accepted
    if (isAccepted(str, numStates, initialState, acceptingStates, numAcceptingStates, transitions, numSymbols, symbols)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}