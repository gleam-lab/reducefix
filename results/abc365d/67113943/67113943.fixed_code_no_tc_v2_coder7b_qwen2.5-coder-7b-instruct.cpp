#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char winmove = 'a', prev = 'a';

    // Iterate through each move in Aoki's sequence
    for (char c : S) {
        if (c == 'R') {
            winmove = 'P'; // Takahashi should play Paper to win against Rock
        } else if (c == 'P') {
            winmove = 'S'; // Takahashi should play Scissors to win against Paper
        } else if (c == 'S') {
            winmove = 'R'; // Takahashi should play Rock to win against Scissors
        }

        // Check if Takahashi can make a different move than the previous one
        if (winmove != prev && (wins + 1 <= N)) { 
            wins++; // Increment the number of wins
            prev = winmove; // Update the previous move
        } else {
            prev = c; // If not possible, take Aoki's move as next
        }
    }

    cout << wins; // Output the maximum number of wins
    return 0;
}