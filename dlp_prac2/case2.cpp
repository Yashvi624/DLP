#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Define DFA details
    int numInputSymbols = 2;  // Number of input types: [a-z], [0-9]
    int numStates = 3;        // q1, q2, q_reject
    vector<string> states = {"q1", "q2", "q_reject"};  // State names
    int initialState = 0;     // Initial state (q1)
    vector<int> finalStates = {1}; // Final state (q2)

    // Transition table: Rows represent states, columns represent input types
    vector<vector<int>> transitionTable = {
        {1, 2},  // q1: [a-z] -> q2, others -> q_reject
        {1, 1},  // q2: [a-z, 0-9] -> q2
        {2, 2}   // q_reject: Trap state
    };

    // Display DFA details
    cout << "DFA Details:\n";
    cout << "No. of input symbols: 2 ([a-z], [0-9])\n";
    cout << "No. of states: " << numStates << " (";
    for (size_t i = 0; i < states.size(); ++i) {
        cout << states[i] << (i < states.size() - 1 ? ", " : "");
    }
    cout << ")\n";
    cout << "Initial state: " << states[initialState] << "\n";
    cout << "No. of final states: " << finalStates.size() << "\n";
    cout << "Final state(s): ";
    for (size_t i = 0; i < finalStates.size(); ++i) {
        cout << states[finalStates[i]] << (i < finalStates.size() - 1 ? ", " : "");
    }
    cout << "\n\n";

    // User input string
    string inputString;
    cout << "Enter a string over [a-z, 0-9]: ";
    cin >> inputString;

    // Process the input string
    int currentState = initialState;
    for (char c : inputString) {
        int inputIndex;

        // Determine the input type: 0 for [a-z], 1 for [0-9], else reject
        if (c >= 'a' && c <= 'z') {
            inputIndex = 0;
        } else if (c >= '0' && c <= '9') {
            inputIndex = 1;
        } else {
            inputIndex = -1; // Invalid character
        }

        // Validate input
        if (inputIndex == -1 || currentState == 2) {
            currentState = 2; // Move to reject state
            break;
        }

        // Perform state transition
        currentState = transitionTable[currentState][inputIndex];
    }

    // Check if final state is valid
    bool isAccepted = (currentState == 1);
    if (isAccepted) {
        cout << "The string is accepted.\n";
    } else {
        cout << "The string is rejected.\n";
    }

    return 0;
}
