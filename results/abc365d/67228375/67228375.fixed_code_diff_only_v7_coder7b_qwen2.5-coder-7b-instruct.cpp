#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Initialize variables to keep track of the number of moves that can be made
    int total_1 = 1; // Start with one move because we always start a sequence
    char last_move = s[0]; // The first move is our starting point
    
    // Iterate through the string starting from the second character
    for (int i = 1; i < n; i++) {
        // If the current move beats the previous move, increment the count
        if (beats[s[i]] == last_move) {
            total_1++;
        } else {
            // Update the last move to the current move
            last_move = s[i];
        }
    }

    // Reset the variables for the second scenario
    total_1 = 1; // Start with one move again
    last_move = s[n-1]; // Start from the end of the string
    
    // Iterate through the string starting from the second last character
    for (int i = n-2; i >= 0; i--) {
        // If the current move beats the previous move, increment the count
        if (beats[s[i]] == last_move) {
            total_1++;
        } else {
            // Update the last move to the current move
            last_move = s[i];
        }
    }

    // Output the maximum of the two scenarios
    cout << max(total_1, total_2) << endl;

    return 0;
}