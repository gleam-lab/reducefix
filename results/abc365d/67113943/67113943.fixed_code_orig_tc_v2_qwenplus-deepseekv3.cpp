#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char prev_win_move = '\0';

    for (int i = 0; i < N; ) {
        char current = S[i];
        char win_move;
        if (current == 'R') {
            win_move = 'P';
        } else if (current == 'P') {
            win_move = 'S';
        } else { // 'S'
            win_move = 'R';
        }

        int j = i;
        while (j < N && S[j] == current) {
            j++;
        }

        if (win_move != prev_win_move) {
            wins += (j - i);
            prev_win_move = win_move;
        } else {
            prev_win_move = '\0';
        }

        i = j;
    }

    cout << wins << endl;
    return 0;
}