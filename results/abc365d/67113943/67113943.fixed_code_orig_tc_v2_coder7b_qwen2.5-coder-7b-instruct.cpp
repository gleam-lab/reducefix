#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;

    // Initialize variables
    int wins = 0;
    char winmove = 'A'; // Initial value that won't match any move
    char prev = 'A';   // Initial value that won't match any move

    // Iterate through each character in the string
    for (char c : S) {
        // Determine the winning move based on the current character
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else if (c == 'S') {
            winmove = 'R';
        }

        // Check if the previous move was not the same as the current winning move
        if (winmove != prev) {
            wins++; // Increment the number of wins
            prev = winmove; // Update the previous move to the current winning move
        } else {
            prev = c; // Update the previous move to the current character
        }
    }

    // Output the total number of wins
    cout << wins;

    return 0;
}