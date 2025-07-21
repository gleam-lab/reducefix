#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char last_move = ' '; // Track last move made by the bot

    for (char c : S) {
        char best_move;
        if (c == 'R') best_move = 'P';
        else if (c == 'P') best_move = 'S';
        else best_move = 'R';

        if (best_move != last_move) {
            wins++;
            last_move = best_move;
        } else {
            // If we can't use the same move, choose a different one that still beats opponent
            // Example: If opponent played R and our last move was P, we can switch to S
            // This avoids violating the "no repeated moves" rule while still winning
            last_move = c; // We don't win this round, so use opponent's move as placeholder
        }
    }

    cout << wins << endl;
}