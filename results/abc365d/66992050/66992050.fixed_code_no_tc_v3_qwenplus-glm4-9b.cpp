#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    // Initialize the last state and the answer counter
    char lastState = 'N';
    int ans = 0;
    
    // Iterate over each character in the string
    for (char c : S) {
        // Determine the current state based on the character
        char currentState = (c == 'P') ? 'P' : (c == 'R') ? 'R' : 'S';
        
        // Check if there is a change in state
        if (lastState != currentState) {
            ans++; // Increment the answer counter
            lastState = currentState; // Update the last state
        }
    }
    
    // Output the result
    cout << ans;
    return 0;
}