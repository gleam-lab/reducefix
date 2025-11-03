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
            // We cannot use the best counter because we used it last time
            // So we choose any other valid move that isn't the opponent's move or the last move
            if (best_counter != 'R' && c != 'R') {
                last_move = 'R';
            } else if (best_counter != 'P' && c != 'P') {
                last_move = 'P';
            } else if (best_counter != 'S' && c != 'S') {
                last_move = 'S';
            }
            // If none of the above, then we are forced to repeat (but this case shouldn't happen)
            // Actually, one must be available since there are 3 moves and at most two forbidden
        }
    }

    cout << wins;

    return 0;
}