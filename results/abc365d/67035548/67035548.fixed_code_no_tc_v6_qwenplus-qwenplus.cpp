#include <iostream>
#include <string>
using namespace std;

// Function to determine the winner of a RPS move
char winning_move(char opponent) {
    if (opponent == 'R') return 'P'; // Paper beats Rock
    if (opponent == 'P') return 'S'; // Scissors beats Paper
    if (opponent == 'S') return 'R'; // Rock beats Scissors
    return 'X'; // Invalid case
}

int calculate_max_wins(string s, int n) {
    int max_wins = 0;
    char last_move = 'X'; // No move yet

    for (int i = 0; i < n; ++i) {
        char opponent_move = s[i];
        char current_move = winning_move(opponent_move);

        // If we can use the winning move without repeating
        if (current_move != last_move) {
            max_wins++;
            last_move = current_move;
        } else {
            // Can't repeat the same move, so skip this round
            last_move = opponent_move;
        }
    }

    return max_wins;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int forward = calculate_max_wins(s, n);

    // Reverse the string and compute again
    reverse(s.begin(), s.end());
    int backward = calculate_max_wins(s, n);

    cout << max(forward, backward) << endl;

    return 0;
}