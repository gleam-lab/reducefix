#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    long long wins = 0;
    char last_move = 'X'; // No move initially

    for (char c : S) {
        char best_counter = ' ';
        if (c == 'R') best_counter = 'P';
        else if (c == 'P') best_counter = 'S';
        else if (c == 'S') best_counter = 'R';

        if (best_counter != last_move) {
            wins++;
            last_move = best_counter;
        } else {
            // We already played the winning move, so we can play the current opponent's move
            // to potentially set up better for next round
            last_move = c;
        }
    }

    cout << wins;
}