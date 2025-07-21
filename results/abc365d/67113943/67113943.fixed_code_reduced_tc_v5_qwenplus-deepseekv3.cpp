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
    char prev_move = '\0'; // Initialize to null character

    for (char c : S) {
        char optimal_move;
        if (c == 'R') {
            optimal_move = 'P';
        } else if (c == 'P') {
            optimal_move = 'S';
        } else if (c == 'S') {
            optimal_move = 'R';
        }

        if (optimal_move != prev_move) {
            wins++;
            prev_move = optimal_move;
        } else {
            // Do not increment wins, and reset prev_move to allow next move to be different
            prev_move = '\0';
        }
    }
    cout << wins;
    return 0;
}