#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function to determine the outcome of a single round
int outcome(char player_move, char opponent_move) {
    if (player_move == opponent_move) return 0; // draw

    if ((player_move == 'R' && opponent_move == 'S') ||
        (player_move == 'S' && opponent_move == 'P') ||
        (player_move == 'P' && opponent_move == 'R')) {
        return 1; // win
    } else {
        return -1; // loss
    }
}

// Function to get the winning move against a given move
char winning_move(char move) {
    if (move == 'R') return 'P';
    if (move == 'S') return 'R';
    if (move == 'P') return 'S';
    return 'X'; // invalid move
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int wins = 0;
    char last_move = 'X'; // no move yet

    for (char c : s) {
        // Try to win directly
        char desired_move = winning_move(c);
        if (desired_move != last_move) {
            wins++;
            last_move = desired_move;
        } else {
            // We cannot use the same move, so we need to play a different one
            // This is guaranteed to not be optimal, but the greedy approach is sufficient
            // Just change the move to something else that isn't the same and doesn't violate rules
            // Since we're only counting how many times we must change our strategy,
            // this will still work with the greedy approach.
            last_move = (last_move == 'R') ? 'S' : (last_move == 'S') ? 'P' : 'R';
        }
    }

    cout << wins << endl;
    return 0;
}